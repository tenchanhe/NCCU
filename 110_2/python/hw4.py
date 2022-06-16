def check_once(i):
    length = int(i)
    matrix = []
    for b in range(length):
        line = input().split()
        for c in range(length):
            line[c] = int(line[c])
        matrix.append(line)
    
    row = -1
    column = -1
    fail = 0
    for b in range(length):
        
        Sum = 0 
        for c in range(length):
            Sum += matrix[b][c]
        
        if Sum%2 != 0 and row == -1:
            row = b+1

        elif Sum%2 != 0 and row != -1:
            fail = 1
            break

    for b in range(length):
        
        Sum = 0
        for c in range(length):
            Sum += matrix[c][b]

        if Sum%2 != 0 and column == -1:
            column = b+1
        
        elif Sum%2 != 0 and column != -1:
            fail = 1
            break

    if fail == 1:
        print("Corrupt")

    elif row != -1 and column != -1:
        print("Change bit (",row,",",column,")")

    else:
        print("OK")

if __name__ == '__main__':
    i = int(input())
    while i != 0:
        check_once(i)
        i = int(input())

