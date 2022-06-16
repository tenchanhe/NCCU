n = int(input())
for i in range(n):
    ans = ''
    num = int(input())
    while True :
        if num == 1:
            ans += '1'
            break
        if num == 0:
            break

        if num%2 == 0:
            num = num//2
            ans += '0'
        else:
            num = num//2
            ans += '1'
    print(ans[::-1])
