對的
prompt = [{"role": "user", "content": "<s>[INST]<<SYS>>\n" + "Given the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis." + "<<\SYS>>\n" + \
               abstract + "[/INST]"}]

prompt = [{"role": "user", "content": "<s>[INST]<<SYS>>\n" + "Methodological sentences are those that describe the methods or approaches used in the research, including experimental setup, data collection, analysis techniques, and procedures followed. Given the abstracts of academic articles, and there are one or more methodological sentences in each abstracts. Your goal is to extract methodological sentences from the abstracts of academic articles. Only provide the original sentences from the abstract, no additional explanation required." + "<<\SYS>>\n" + \
               abstract + "[/INST]"}]

    instruction = tokenizer(f"<s>[INST]<<SYS>>\nMethodological sentences are those that describe the methods or approaches used in the research, including experimental setup, data collection, analysis techniques, and procedures followed. Given the abstracts of academic articles, and there are one or more methodological sentences in each abstracts. Your goal is to extract methodological sentences from the abstracts of academic articles. Only provide the original sentences from the abstract, no additional explanation required.<</SYS>>\n\n{example['abstract']}[/INST]", add_special_tokens=False)  # add_special_tokens 不在开头加 special_tokens


mess = [{"role": "user", "content": "<s>[INST]<<SYS>>\n" + "Given the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis." + "<<\SYS>>\n" + "The reliability of self-labeled data is an important issue when the data are regarded as ground-truth for training and testing learning-based models.This paper addresses the issue of false-alarm hashtags in the self-labeled data for irony detection.We analyze the ambiguity of hashtag usages and propose a novel neural network-based model, which incorporates linguistic information from different aspects, to disambiguate the usage of three hashtags that are widely used to collect the training data for irony detection.Furthermore, we apply our model to prune the self-labeled training data.Experimental results show that the irony detection model trained on the less but cleaner training instances outperforms the models trained on all data." + "[/INST]"}]

mess = [{"role": "user", "content": "<s>[INST]<<SYS>>\n" + "Given the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis." + "<<\SYS>>\n" + prompt + "[/INST]"}]


[{'role': 'user', 'content': '<s>[INST]<<SYS>>\nGiven the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis.<<\\SYS>>\nThe reliability of self-labeled data is an important issue when the data are regarded as ground-truth for training and testing learning-based models.\nThis paper addresses the issue of false-alarm hashtags in the self-labeled data for irony detection.\nWe analyze the ambiguity of hashtag usages and propose a novel neural network-based model, which incorporates linguistic information from different aspects, to disambiguate the usage of three hashtags that are widely used to collect the training data for irony detection.\nFurthermore, we apply our model to prune the self-labeled training data.\nExperimental results show that the irony detection model trained on the less but cleaner training instances outperforms the models trained on all data.[/INST]'}]

[{'role': 'user', 'content': '<s>[INST]<<SYS>>\nGiven the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis.<<\\SYS>>\nThe reliability of self-labeled data is an important issue when the data are regarded as ground-truth for training and testing learning-based models.This paper addresses the issue of false-alarm hashtags in the self-labeled data for irony detection.We analyze the ambiguity of hashtag usages and propose a novel neural network-based model, which incorporates linguistic information from different aspects, to disambiguate the usage of three hashtags that are widely used to collect the training data for irony detection.Furthermore, we apply our model to prune the self-labeled training data.Experimental results show that the irony detection model trained on the less but cleaner training instances outperforms the models trained on all data.[/INST]'}]




