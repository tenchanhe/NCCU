class Data:
    def __init__(self, ID, name, grade, special):
        self.ID = ID
        self.name = name
        self.grade = grade
        self.special = special
        self.spgrade = 0
        if special == 1:
            self.spgrade = min(max(grade*5/2-20,0),100)
        else:
            self.spgrade = min(max(grade*3/2-10,0),100)

if __name__ == '__main__':
    dic = {}
    while True:
        try:
            cmd = input().split()
            
            if cmd[0] == 'i':
                dic[cmd[1]] = Data(int(cmd[1]),cmd[2],int(cmd[3]),int(cmd[4]))

            elif cmd[0] == 'd':
                if cmd[1] in dic:
                    del dic[cmd[1]]
                else:
                    print('ID',cmd[1],'does not exist!')

            elif cmd[0] == 'qg':
                if cmd[1] in dic:
                    print(dic[cmd[1]].grade)
                else:
                    print('ID',cmd[1],'does not exist!')
            
            elif cmd[0] == 'qn':
                if cmd[1] in dic:
                    print(dic[cmd[1]].name)
                else:
                    print('ID',cmd[1],'does not exist!')
            
            elif cmd[0] == 'pg':
                for key in sorted(dic, key = lambda key:dic[key].ID):
                    print(key,dic[key].name,dic[key].grade)
            
            elif cmd[0] == 'pm':
                for key in sorted(dic, key = lambda key:dic[key].ID):
                    print(key,dic[key].name,dic[key].spgrade)
                
        except EOFError:
            exit()
