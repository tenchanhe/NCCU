import json

if __name__ == "__main__":
    # 讀取 test.txt
    with open('test_data.txt', 'r') as file:
        lines = file.readlines()

    # 初始化資料列表
    data = []

    # 用"=*100"分割資料並處理
    for line in lines:
        if line.strip() == '=*100':
            continue
        if line[:8] == 'abstract':
            parts = line.strip().split(': ')
            if len(parts) == 2:
                data.append({
                    'abstract': parts[1]
                }) 
        if line[:8] == 'response':
            parts = line.strip().split(': ')
            if len(parts) == 2:
                data.append({
                    'response': parts[1]
                })

    # 寫入 test.json
    with open('test_data.json', 'w') as file:
        json.dump(data, file, indent=4)
