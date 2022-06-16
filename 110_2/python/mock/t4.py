n = int(input())
l = n+n-1
num = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
num = num + num + num + num
book = []
zhujiao = num[n-1]
headtail = list(range(l))

for i in range(n):
    zhujiao = num[n-1-i]
    for j in range(i+1):
        headtail[j] = num[n-1-j]
    
    word = list(range(l))
    
    for j in range(i+1):
        word[j] = headtail[j]
        word[l-1-j] = headtail[j]
    
    a = l-(2*(i+1))
    if a < 0:
        a = 0
    for j in range(a):
        word[j+i+1] = zhujiao
    
    for j in range(l):
        print(word[j],end='')
    print('')
    book.append(word)
b = len(book)
for i in range(b-2,1,-1):
    for j in range(l):
        print(book[i][j],end='')
    print('')
