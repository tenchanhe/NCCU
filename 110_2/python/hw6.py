
if __name__ == '__main__':
    dic = {}
    while True:
        try:
            cmd = input().split()
        
            if cmd[0] == 'i':
                dic[cmd[1]] = int(cmd[2])

            elif cmd[0] == 'd':
                if cmd[1] in dic:
                    del dic[cmd[1]]
                else:
                    print(cmd[1],'does not exist!')

            elif cmd[0] == 'q':
                if cmd[1] in dic:
                    print(dic.get(cmd[1]))
                else:
                    print(cmd[1],'does not exist!')

            elif cmd[0] == 'p':
                dic = dict(sorted(dic.items(), key = lambda item:item[1], reverse = True))
                for i in dic:
                    print(i,dic[i])
            
        except:
            exit()

