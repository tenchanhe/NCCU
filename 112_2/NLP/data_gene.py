import pandas as pd
import ollama


def get_data():
    data = []
    df = pd.read_parquet('./train-00000-of-00001-d9a274137f7fc7c8.parquet')
    data.append("The reliability of self-labeled data is an important issue when the data are regarded as ground-truth for training and testing learning-based models.This paper addresses the issue of false-alarm hashtags in the self-labeled data for irony detection.We analyze the ambiguity of hashtag usages and propose a novel neural network-based model, which incorporates linguistic information from different aspects, to disambiguate the usage of three hashtags that are widely used to collect the training data for irony detection.Furthermore, we apply our model to prune the self-labeled training data.Experimental results show that the irony detection model trained on the less but cleaner training instances outperforms the models trained on all data.")

    for index, row in df.iterrows():
        data.append(row['response'])
        # print(row['response'])
    return data


if __name__ == "__main__":
    data = get_data()

    for abstract in data:
        print('abstract: ', abstract)
        response = ollama.chat(model='llama3', messages=[
            {
                'role': 'system',
                # 'content': 'Your goal is to summarize the text given to you in roughly 300 words. It is from a meeting between one or more people. Only output the summary without any additional text. Focus on providing a summary in freeform text with what people said and the action items coming out of it.'
                'content': 'Extract the sentences describing the experimental methods from the abstract of the research paper. Only provide the original sentences from the abstract, no additional explanation required.'
            },
            {
                'role': 'user',
                'content': abstract,
            },
        ])

        print('\n', 'response: ', response['message']['content'])
        print("="*100)
        print("")
