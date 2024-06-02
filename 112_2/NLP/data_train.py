import json
import ollama


def get_data():
    data_return = []
    with open('./cleaned.json', 'r') as file:
        data = json.load(file)

    i = 1
    for item in data[:100]:
        print(i)
        i+=1
        data_return.append(item['Summary'])
        # print(item['Summary'])

    return data_return


if __name__ == "__main__":
    data = get_data()
    train_data = []

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
        train_data.append({
            'abstract': abstract,
            'response': response['message']['content']
        })

        print('\n', 'response: ', response['message']['content'])
        print("="*100, '\n')

    with open('train_data.json', 'w') as file:
        json.dump(train_data, file)
