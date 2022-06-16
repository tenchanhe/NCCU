count = 0
def bsearch(num, target):
    global count
    low = 0
    upper = len(num)
    while low < upper:
        count += 1
        mid = (low + upper) / 2
        mid = int(mid)
        if num[mid] < target: 
            low = mid + 1
        elif num[mid] > target:
            upper = mid
        else:                
            return mid
    return -1

if __name__ == '__main__':
    target = int(input())
    num = input().split()
    for i in range(len(num)):
        num[i] = int(num[i])
    
    ans = bsearch(num,target)
    print(ans)
    if ans != -1:
        print(count)
