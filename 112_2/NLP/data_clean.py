import json

def longest_common_substring(s1, s2):
    # Find the longest common substring between s1 and s2
    m = [[0] * (1 + len(s2)) for i in range(1 + len(s1))]
    longest, x_longest = 0, 0
    for x in range(1, 1 + len(s1)):
        for y in range(1, 1 + len(s2)):
            if s1[x - 1] == s2[y - 1]:
                m[x][y] = m[x - 1][y - 1] + 1
                if m[x][y] > longest:
                    longest = m[x][y]
                    x_longest = x
            else:
                m[x][y] = 0
    return s1[x_longest - longest: x_longest]

# 读取 JSON 文件
# with open('test_data.json', 'r') as infile:
with open('train_data.json', 'r') as infile:
    data = json.load(infile)

# 处理每个 dict
for entry in data:
    # print(entry)
    abstract = entry['abstract']
    response = entry['response']
    longest_substring = longest_common_substring(abstract, response)
    entry['response'] = longest_substring

# 写回 JSON 文件
# with open('test_data_clean.json', 'w') as outfile:
with open('train_data_clean.json', 'w') as outfile:
    json.dump(data, outfile, indent=4)

print("Processing complete.")
