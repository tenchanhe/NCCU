dna = input()
ans = ''
for i in range(len(dna)):
    if dna[i] == 'A':
        ans = ans + 'U'
    elif dna[i] == 'T':
        ans = ans + 'A'
    elif dna[i] == 'C':
        ans = ans + 'G'
    elif dna[i] == 'G':
        ans = ans + 'C'
print(ans)
