import json

if __name__ == "__main__":
    data = []

    with open('split_data/output_part_3.jsonl', 'r', encoding='utf-8') as file:
        for i, line in enumerate(file):
            # data.append(json.loads(line))
            if i < 10000:  # 只读取前 100 行
                data.append(json.loads(line))
            else:
                break

    with open('newwPrompt_train_data.json', 'r', encoding='utf-8') as file:
        new_data = json.load(file)

    print(len(new_data))
    # print(new_data[0]['abstract'][:20])
    # print(data[0])

    # for line in range(len(new_data)):
    #     if new_data[line]['abstract'][:20] == data[line]['abstract'][:20]:
    #         print(data[line]['id'])
    #         new_data[line]['id'] = data[line]['id']
    #     else:
    #         print(new_data[0]['abstract'][:20])

    # with open('newwwwwwwwwPrompt_train_data.json', 'w', encoding='utf-8') as outfile:
    #     json.dump(new_data, outfile, indent=4)


