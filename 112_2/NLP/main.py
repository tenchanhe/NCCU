import ollama
import json

if __name__ == "__main__":

        abstract = "Abstractive summarization models often generate factually inconsistent content particularly when the parametric knowledge of the model conflicts with the knowledge in the input document. In this paper, we analyze the robustness of fine-tuning based summarization models to the knowledge conflict, which we call factual adaptiveness. We utilize pre-trained language models to construct evaluation sets and find that factual adaptiveness is not strongly correlated with factual consistency on original datasets. Furthermore, we introduce a controllable counterfactual data augmentation method where the degree of knowledge conflict within the augmented data can be adjustable. Our experimental results on two pre-trained language models (PEGASUS and BART) and two fine-tuning datasets (XSum and CNN/DailyMail) demonstrate that our method enhances factual adaptiveness while achieving factual consistency on original datasets on par with the contrastive learning baseline."
        response = ollama.chat(model='llama3', messages=[
            {
                'role': 'system',
                # 'content': 'Your goal is to extract the sentences describing the experimental methods from the abstract of the research paper. Only provide the original sentences from the abstract, no additional explanation required.'
                'content': 'Methodological sentences are those that describe the methods or approaches used in the research, including experimental setup, data collection, analysis techniques, and procedures followed. Given the abstracts of academic articles, and there are one or more methodological sentences in each abstracts. Your goal is to extract methodological sentences from the abstracts of academic articles. Only provide the original sentences from the abstract, no additional explanation required.'
            },
            {
                'role': 'user',
                'content': abstract,
            },
        ])

        print('\n', 'response: ', response['message']['content'])
        print("="*100, '\n')