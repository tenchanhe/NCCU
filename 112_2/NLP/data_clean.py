import json
import re

def clean_text(text):
    # 去掉换行符号和星号
    text = text.replace('\n', '')
    text = text.replace('*', '')
    text = text.replace('"', '')
    text = text.replace('\\', '')

    # 找到第一个冒号、换行符号或星号，并去掉其之前的部分
    first_colon_index = text.find(':')
    if first_colon_index != -1:
        text = text[first_colon_index + 1:].strip()

    return text


if __name__ == "__main__":
    # 读取json文件
    with open('newwPrompt_train_data.json', 'r', encoding='utf-8') as file:
        data = json.load(file)

    # print(data[0]['abstract'])
    # print(data[0]['method'])
    # print("CCCCCC=", clean_text(data[0]['method']))
    # 对每条数据进行处理
    for item in data:
        if 'method' in item:
            item['method'] = clean_text(item['method'])

    # 将处理后的数据写回json文件
    with open('clean_train_data.json', 'w', encoding='utf-8') as file:
        json.dump(data, file, ensure_ascii=False, indent=4)
