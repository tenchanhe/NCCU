n = int(input())
for i in range(n):
    num = input().split()
    num[0] = int(num[0])
    num[2] = int(num[2])

    if num[1] == '+':
        print(num[0]+num[2])
    elif num[1] == '-':
        print(num[0]-num[2])
    elif num[1] == '*':
        print(num[0]*num[2])
    elif num[1] == '/':
        print(num[0]/num[2])
