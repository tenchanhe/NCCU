n = int(input())
num = input().split()
count = 0
for i in range(n):
    num[i] = int(num[i])

for i in range(n):
    for j in range(n-1-i):
        if num[j] < num[j+1]:
            count += 1
            tmp = num[j]
            num[j] = num[j+1]
            num[j+1] = tmp

for i in range(n):
    if i != n-1:
        print(num[i],end=' ')
    else:
        print(num[i])
print(count)
