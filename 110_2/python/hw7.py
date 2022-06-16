class student:
    def __init__(self,ID,name,score):
        self.ID = ID
        self.name = name
        self.score = score

if __name__ == '__main__':
    dic = {}
    while True:
        try:
            cmd = input().split()

            if cmd[0] == 'i':
                dic[cmd[1]] = student(int(cmd[1]),cmd[2],int(cmd[3]))

            elif cmd[0] == 'd':
                if cmd[1] in dic:
                    del dic[cmd[1]]
                else:
                    print('ID',cmd[1],'does not exist!')

            elif cmd[0] == 'qg':
                if cmd[1] in dic:
                    print(dic[cmd[1]].score)
                else:
                    print('ID',cmd[1],'does not exist!')
            
            elif cmd[0] == 'qn':
                if cmd[1] in dic:
                    print(dic[cmd[1]].name)
                else:
                    print('ID',cmd[1],'does not exist!')
            
            elif cmd[0] == 'pg':
                for key in sorted(dic, key = lambda key:dic[key].score):
                    print(key,dic[key].name,dic[key].score)
            
            elif cmd[0] == 'pi':
                for key in sorted(dic, key = lambda key:dic[key].ID):
                    print(key,dic[key].name,dic[key].score)
        
        except:
            exit()
