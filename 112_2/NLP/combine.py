import json

if __name__ == "__main__":
    # 讀取 test.json
    with open('test_data_orpo.json', 'r') as file:
        test_data = json.load(file)

    # 讀取 train.json
    with open('train_data_orpo.json', 'r') as file:
        train_data = json.load(file)

    # 合併資料
    data = {
        'train': train_data,
        'test': test_data
    }

    # 寫入 data.json
    with open('data_orpo.json', 'w') as file:
        json.dump(data, file, indent=4)
