while True:
    try:
        num = input().split()
        for i in range(len(num)-1,-1,-1):
            print(num[i],end=' ')

        print('')
    except EOFError:
        exit()
