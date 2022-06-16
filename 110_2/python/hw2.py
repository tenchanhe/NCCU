def gcd(x,y):
    if x % y == 0:
        return y
    else:
        return gcd(y,x%y)

n = int(input())
for i in range(0,n):
    x,y = input().split()
    x = int(x)
    y = int(y)
    
    if x > y:
        ans = gcd(x,y)
    else:
        ans = gcd(y,x)
    
    print(ans)

