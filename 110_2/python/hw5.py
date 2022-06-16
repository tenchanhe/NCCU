word = list(map(str,input().split(',')))
word.sort()
#print(word)
dic = {}
num = 1
for i in word:
    if i[0] != word[word.index(i)-1][0]:
        num = 1

    page = i[0].upper() + ' ' + str(num)
    dic[i] = page
    num += 1

#print(dic)

while True:
    try:
        find = input()
        print(dic.get(find,'NOT FOUND'))

    except:
        exit()
