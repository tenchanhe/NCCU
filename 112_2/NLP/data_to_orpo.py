import json

# with open('test_data.json', 'r') as infile:
with open('train_data.json', 'r') as infile:
    data = json.load(infile)

new_data = []

for entry in data:
    new_entry = {
        "prompt": f"<s>[INST]<<SYS>>\nGiven the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis.\n<<\\SYS>>\n{entry['abstract']}[/INST]",
        "chosen": [{ "content": f"<s>[INST]<<SYS>>\nGiven the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis.\n<<\\SYS>>\n{entry['abstract']}[/INST]", "role": "user" }, {"content": entry["response"], "role": "assistant"}],
        "rejected": [{ "content": f"<s>[INST]<<SYS>>\nGiven the abstract of a research paper, extract the section discussing the experimental methodology (Method). The experimental method section typically appears in the middle of the abstract. Please extract the original text from the abstract for analysis.\n<<\\SYS>>\n{entry['abstract']}[/INST]", "role": "user" }, {"content": "None", "role": "assistant"}]
    }
    new_data.append(new_entry)

# with open('test_data_orpo.json', 'w') as outfile:
with open('train_data_orpo.json', 'w') as outfile:
    json.dump(new_data, outfile, indent=4)

print("Processing complete.")
