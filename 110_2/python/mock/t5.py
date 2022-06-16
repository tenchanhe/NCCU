class Complex:
    def __init__(self,a,b):
        self.real = a
        self.imagine = b

    def __add__(self,other):
        real = self.real + other.real
        imagine = self.imagine + other.imagine
        return Complex(real,imagine)

    def __sub__(self,other):
        real = self.real - other.real
        imagine = self.imagine - other.imagine
        return Complex(real,imagine)

    def __mul__(self,other):
        real = self.real*other.real + self.imagine*other.imagine
        imagine = self.real*other.imagine + self.imagine*other.real
        return Complex(real,imagine)

    def __str__(self):
        if self.imagine == 0:
            return str(self.real)
        else:
            if self.imagine > 0:
                return '{}+{}i'.format(self.real,self.imagine)
            else:
                return '{}{}i'.format(self.real,self.imagine)

    def conjugate(self):
        pass

if __name__ == "__main__":
    tmp = input().split(" ")
    a = Complex(int(tmp[0]), int(tmp[1]))
    tmp = input().split(" ")
    b = Complex(int(tmp[0]), int(tmp[1]))
    command = input()
    if command == "add":
        print(a+b)
    elif command == "sub":
        print(a-b)
    elif command == "mul":
        print(a*b)
    elif command == "conjugate":
        print(a.conjugate())
        print(b.conjugate())
