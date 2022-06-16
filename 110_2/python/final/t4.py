n = int(input())
target = input()
trg = []

for i in range(1,n+2):
    s = 1
    a = n
    b = i
    num = []
    for j in range(1,i+1):
        num.append(s)
        s = int(s*(i-j)/j)
    trg.append(num)

#print(trg)
word = ''
for i in range(len(trg[n])):
        word = word + str(trg[n][i])
#print(word)
count = 0
for i in range(len(word)):
    if word[i] == target:
        count += 1

print(count)
