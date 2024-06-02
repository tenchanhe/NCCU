import json

# # 读取 JSON 文件
# with open('train_data.json', 'r') as infile:
#     data = json.load(infile)

# # 以 4 格缩进的方式写入 JSON 文件
# with open('train_data.json', 'w') as outfile:
#     json.dump(data, outfile, indent=4)

# 读取 JSON 文件
with open('test_data.json', 'r') as infile:
    data = json.load(infile)

# 初始化合并后的数据列表
merged_data = []

# 临时存储当前的abstract和response
current_entry = {}

# 遍历每个 dict
for entry in data:
    if 'abstract' in entry:
        current_entry['abstract'] = entry['abstract']
    if 'response' in entry:
        current_entry['response'] = entry['response']
    
    # 当同时拥有abstract和response时，添加到merged_data并重置current_entry
    if 'abstract' in current_entry and 'response' in current_entry:
        merged_data.append(current_entry)
        current_entry = {}

# 写回合并后的 JSON 文件
with open('test_data.json', 'w') as outfile:
    json.dump(merged_data, outfile, indent=4)

print("Processing complete. Output written to 'test_data.json'.")
