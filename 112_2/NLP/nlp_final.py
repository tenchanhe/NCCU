import torch
import pandas as pd
import transformers
import argparse
import json
from transformers import AutoModelForCausalLM, AutoTokenizer, DataCollatorForSeq2Seq, Trainer, BitsAndBytesConfig
from datasets import load_dataset, DatasetDict
from peft import (
        get_peft_model,
        prepare_model_for_kbit_training,
        LoraConfig
    )
from trl import SFTTrainer
from huggingface_hub import login
from peft import AutoPeftModelForCausalLM
from peft import PeftModel
import logging
import time
import argparse
from typing import Optional, Union
from rouge_score import rouge_scorer



login(token="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")

lora_config = LoraConfig(
        r=8,
        lora_alpha=32,
        lora_dropout=0.1,
        target_modules = 'all-linear',
        task_type="CAUSAL_LM",
    )



tokenizer = AutoTokenizer.from_pretrained("meta-llama/Llama-2-7b-hf", trust_remote_code=True)

mode_path = 'apple/OpenELM-1_1B-Instruct'
lora_path = '/Users/tenchanhe/Desktop/自然語言處理/train_apple4000-5000' # lora权重路径

# 加载模型
model = AutoModelForCausalLM.from_pretrained(mode_path, device_map="auto",torch_dtype=torch.bfloat16, trust_remote_code=True)

model.enable_input_require_grads()

# 加载lora权重
model = PeftModel.from_pretrained(model, model_id=lora_path, config=lora_config)


def generate(
    prompt: str,
    model: Union[str, AutoModelForCausalLM],
    hf_access_token: str = None,
    tokenizer: Union[str, AutoTokenizer] = 'meta-llama/Llama-2-7b-hf',
    device: Optional[str] = None,
    max_length: int = 1024,
    assistant_model: Optional[Union[str, AutoModelForCausalLM]] = None,
    generate_kwargs: Optional[dict] = None,
) -> str:
    """ Generates output given a prompt.
    Args:
        prompt: The string prompt.
        model: The LLM Model. If a string is passed, it should be the path to
            the hf converted checkpoint.
        hf_access_token: Hugging face access token.
        tokenizer: Tokenizer instance. If model is set as a string path,
            the tokenizer will be loaded from the checkpoint.
        device: String representation of device to run the model on. If None
            and cuda available it would be set to cuda:0 else cpu.
        max_length: Maximum length of tokens, input prompt + generated tokens.
        assistant_model: If set, this model will be used for
            speculative generation. If a string is passed, it should be the
            path to the hf converted checkpoint.
        generate_kwargs: Extra kwargs passed to the hf generate function.
    Returns:
        output_text: output generated as a string.
        generation_time: generation time in seconds.
    Raises:
        ValueError: If device is set to CUDA but no CUDA device is detected.
        ValueError: If tokenizer is not set.
        ValueError: If hf_access_token is not specified.
    """
    if not device:
        if torch.cuda.is_available() and torch.cuda.device_count():
            device = "cuda:0"
            logging.warning(
                'inference device is not set, using cuda:0, %s',
                torch.cuda.get_device_name(0)
            )
        else:
            device = 'cpu'
            logging.warning(
                (
                    'No CUDA device detected, using cpu, '
                    'expect slower speeds.'
                )
            )

    if 'cuda' in device and not torch.cuda.is_available():
        raise ValueError('CUDA device requested but no CUDA device detected.')

    if not tokenizer:
        raise ValueError('Tokenizer is not set in the generate function.')

    if not hf_access_token:
        raise ValueError((
            'Hugging face access token needs to be specified. '
            'Please refer to https://huggingface.co/docs/hub/security-tokens'
            ' to obtain one.'
            )
        )

    if isinstance(model, str):
        checkpoint_path = model
        model = AutoModelForCausalLM.from_pretrained(
            checkpoint_path,
            trust_remote_code=True
        )
    model.to(device).eval()
    if isinstance(tokenizer, str):
        tokenizer = AutoTokenizer.from_pretrained(
            tokenizer,
            token=hf_access_token,
        )

    # Speculative mode
    draft_model = None
    if assistant_model:
        draft_model = assistant_model
        if isinstance(assistant_model, str):
            draft_model = AutoModelForCausalLM.from_pretrained(
                assistant_model,
                trust_remote_code=True
            )
        draft_model.to(device).eval()

    # Generate
    stime = time.time()
    generation_time = time.time() - stime

    text = tokenizer.apply_chat_template(prompt, tokenize=False, add_generation_prompt=True)

    ## 注意注意
    # model_inputs = tokenizer([text], return_tensors="pt").to('cuda')
    model_inputs = tokenizer([text], return_tensors="pt").to('cpu')

    generated_ids = model.generate(
        model_inputs.input_ids,
        max_new_tokens=512,
        eos_token_id=tokenizer.encode('[/INST]')[0]
    )
    generated_ids = [
        output_ids[len(input_ids):] for input_ids, output_ids in zip(model_inputs.input_ids, generated_ids)
    ]

    response = tokenizer.batch_decode(generated_ids, skip_special_tokens=True)[0]
    string = response.split('[/INST]')
    print(string)
    # output = string[0]+string[1]

    # return output, generation_time
    return response, generation_time

def extract_sentence(abstract: str) -> str:
    abstract = abstract.replace('\n', '')
    # prompt = "<s>[INST]<<SYS>>\n" + \
    #          "Given the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis." + \
    #          "<<\SYS>>\n" + \
    #          abstract + "[/INST]"
    # print(prompt)
    prompt = [{"role": "user", "content": "<s>[INST]<<SYS>>\n" + "Given the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis." + "<<\SYS>>\n\n" + \
               abstract + "[/INST]"}]
    output_text, genertaion_time = generate(
        prompt=prompt,
        # model="apple/OpenELM-1_1B-Instruct",
        # model="ChanHE/OpenELM-1B-LORA-nlp-final",
        model = model,
        hf_access_token="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",
        tokenizer=tokenizer,
        # device="mps",
        device = 'cpu',
        # assistant_model="microsoft/Phi-3-mini-128k-instruct"
    )
    return output_text


if __name__ == "__main__":    
    df=pd.read_excel('/Users/tenchanhe/Desktop/自然語言處理/training_data_2.xlsm')
print(len(df))

data = []
for i in range(len(df)):

    scorer = rouge_scorer.RougeScorer(['rougeL'])

    # print(df.iloc[i])
    # print(type(df[i]['abstract']))
    aaa = extract_sentence(df.iloc[i]['abstract'])
    # abstractsss.append(aaa)
    compare = scorer.score(df.iloc[i]['method'], aaa)['rougeL'].fmeasure
    print(compare)
    data.append({'ans':df.iloc[i]['method'],
                 'res':aaa,
                 'score':compare})

    with open('result.json', 'w', encoding='utf-8') as outfile:
        json.dump(data, outfile, indent=4)