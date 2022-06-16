class Matrix:
    def __init__(self,a,b,c=[]):
        self.h = a
        self.w = b
        self.mat = c

    def __mul__(self,other):
        if self.w == other.h:
            ans = []
            for i in range(self.h):
                num = []
                for j in range(other.w):
                    Sum = 0
                    for k in range(self.w):
                        Sum = Sum + (self.mat[i][k]*other.mat[k][j])
                    num.append(Sum)
                ans.append(num)

            print(ans)
            return Matrix(self.h,other.w,ans)
        else:
            return 'a'

    def __str__(self):
        pass


if __name__ == '__main__':
    while True:
        try:
            h, w = input().split(' ')
            h = int(h)
            w = int(w)
            mat = []
            for i in range(h):
                line = input().split()
                for j in range(w):
                    line[j] = int(line[j])
                mat.append(line)
            a = Matrix(h, w, mat)
            h, w = input().split(' ')
            h = int(h)
            w = int(w)
            mat = []
            for i in range(h):
                line = input().split()
                for j in range(w):
                    line[j] = int(line[j])
                mat.append(line)
            b = Matrix(h, w, mat)
            try:
                print(str(a*b),end='')
            except ValueError:
                print('Invalid calculation!!')
        except EOFError:
            exit()
