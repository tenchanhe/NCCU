import json
import re

with open('result.json', 'r', encoding='utf-8') as file:
# with open('/Users/tenchanhe/Desktop/自然語言處理/result_100.json', 'r', encoding='utf-8') as file:
# with open('/Users/tenchanhe/Desktop/自然語言處理/result.json', 'r', encoding='utf-8') as file:
# with open('/Users/tenchanhe/Desktop/自然語言處理/result_2.json', 'r', encoding='utf-8') as file:
    data = json.load(file)

Sum = 0
for d in data:
    Sum += d['score']

print(Sum/len(data))