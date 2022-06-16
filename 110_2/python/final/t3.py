num = input().split()
a = int(num[0])
b = int(num[1])
ans = 0
if a > b:
    big = a
else:
    big = b

while True:
    if big%a == 0 and big%b == 0:
        ans = big
        break
    big = big + 1

print(ans)

