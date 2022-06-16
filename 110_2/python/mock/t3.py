index = input().split()
num = '1234567890'
for i in range(len(index)):
#    if type(index[i]) == int:
    try:
        index[i] = float(index[i])
    except ValueError:
        pass
while True:
    try:
        cmd = input().split()
        cmd[0] = int(cmd[0])
        cmd[1] = int(cmd[1])

        try:
            print(index[cmd[0]]/index[cmd[1]])
        except IndexError:
            print('Index out of range!')
        except ZeroDivisionError:
            print('Could not divide by zero!')
        except:
            print('Value error occurred!')
    
    except EOFError:
        exit()
