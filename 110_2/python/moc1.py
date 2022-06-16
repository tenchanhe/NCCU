res = input().split()
n = len(res)
score = []
for i in range(n):
    s = input().split()
    score.append(s)

for i in range(n):
    for j in range(len(score[i])):
        score[i][j] = int(score[i][j])

for i in range(n):
    for j in range(len(score[i])):
        for k in range(len(score[i])-j-1):
            if score[i][k] < score[i][k+1]:
                tmp = score[i][k]
                score[i][k] = score[i][k+1]
                score[i][k+1] = tmp

for i in range(n):
    for j in range(n-i-1):
        flag=0
        while score[j][flag] == score[j+1][flag]:
            flag += 1

        if score[j][flag] < score[j+1][flag]:
            tmp = score[j]
            score[j] = score[j+1]
            score[j+1] = tmp

for i in range(n):
    print(res[i],end = ' ')
    for j in range(len(score[i])):
            print(score[i][j],end = ' ')
    print('')

print('---')
print('Average Score:')
ans = []
for i in range(n):
    avr = 0
    for j in range(len(score[i])):
        avr = avr + float(score[i][j])
    ans.append([res[i],avr/len(score[i])])

for i in range(n):
    for j in range(n-i-1):
        if ans[j][1] < ans[j+1][1]:
            tmp = ans[j]
            ans[j] = ans[j+1]
            ans[j+1] = tmp

for i in range(n):
    print(ans[i][0],round(ans[i][1],2))
