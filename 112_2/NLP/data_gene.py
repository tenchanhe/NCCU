import ollama
import json


def get_data():
    data = []

    with open('split_data/output_part_3.jsonl', 'r', encoding='utf-8') as file:
        for i, line in enumerate(file):
            # data.append(json.loads(line))
            # if i < 10000:  # 只读取前 100 行
            #     data.append(json.loads(line))
            # else:
            #     break

            if 9678 <= i < 10000:  # 读取第101到200行
                data.append(json.loads(line))
            elif i >= 10000:  # 超过200行后停止读取
                break
    return data


if __name__ == "__main__":
    Data = get_data()
    print(len(Data))
    flag = 1
    # data=[]
    with open('newwPrompt_train_data.json', 'r', encoding='utf-8') as file:
        data = json.load(file)

    for line in Data:

        print(flag)
        print('abstract: ', line['abstract'])
        response = ollama.chat(model='llama3', messages=[
            {
                'role': 'system',
                # 'content': 'Your goal is to extract the sentences describing the experimental methods from the abstract of the research paper. Only provide the original sentences from the abstract, no additional explanation required.'
                'content': 'Methodological sentences are those that describe the methods or approaches used in the research, including experimental setup, data collection, analysis techniques, and procedures followed. Given the abstracts of academic articles, and there are one or more methodological sentences in each abstracts. Your goal is to extract methodological sentences from the abstracts of academic articles. Only provide the original sentences from the abstract, no additional explanation required.'
            },
            {
                'role': 'user',
                'content': line['abstract'],
            },
        ])

        data.append({
            "abstract":line['abstract'],
            "method":response['message']['content'],
            "id":line['id']
        })

        flag += 1
        with open('newwPrompt_train_data.json', 'w', encoding='utf-8') as outfile:
            json.dump(data, outfile, indent=4)

        print('\n', 'response: ', response['message']['content'])
        print("="*100, '\n')