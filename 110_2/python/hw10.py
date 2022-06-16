class Vector:
    def __init__(self,x,y,z):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self,other):
        new = []
        new.append(self.x + other.x)
        new.append(self.y + other.y)
        new.append(self.z + other.z)
        return new

    def __sub__(self,other):
        new = []
        new.append(self.x - other.x)
        new.append(self.y - other.y)
        new.append(self.z - other.z)
        return new
    
    def __mul__(self,other):
        return self.x*other.x + self.y*other.y +self.z*other.z

    def __xor__(self,other):
        new = []
        new.append(self.y*other.z - self.z*other.y)
        new.append(self.z*other.x - self.x*other.z)
        new.append(self.x*other.y - self.y*other.x)
        return new

    def __eq__(self,other):
        return self.x == other.x and self.y == other.y and self.z == other.z

    def __gt__(self,other):
        a = self.x**2 + self.y**2 + self.z**2
        a = a**0.5
        b = other.x**2 + other.y**2 + other.z**2
        b = b**0.5
        return a > b

    def __lt__(self,other):
        a = self.x**2 + self.y**2 + self.z**2
        a = a**0.5
        b = other.x**2 + other.y**2 + other.z**2
        b = b**0.5
        return a < b

    def __ge__(self,other):
        a = self.x**2 + self.y**2 + self.z**2
        a = a**0.5
        b = other.x**2 + other.y**2 + other.z**2
        b = b**0.5
        return a >= b

    def __le__(self,other):
        a = self.x**2 + self.y**2 + self.z**2
        a = a**0.5
        b = other.x**2 + other.y**2 + other.z**2
        b = b**0.5
        return a <= b

    def __isub__(self,other):
        new = []
        self.x = self.x - other.x
        self.y = self.y - other.y
        self.z = self.z - other.z
        new.append(self.x)
        new.append(self.y)
        new.append(self.z)
        return new

    def __iadd__(self,other):
        new = []
        self.x = self.x + other.x
        self.y = self.y + other.y
        self.z = self.z + other.z
        new.append(self.x)
        new.append(self.y)
        new.append(self.z)
        return new

def calc(a, b, command):
    if command == "add":
        return a + b
    elif command == "sub":
        return a - b
    elif command == "dot":
        return a * b
    elif command == "cross":
        return a ^ b
    elif command == "equal":
        return a == b
    elif command == "greater":
        return a > b
    elif command == "less":
        return a < b
    elif command == "greater_equal":
        return a >= b
    elif command == "less_equal":
        return a <= b
    elif command == "sub_equal":
        a -= b
        return a
    elif command == "add_equal":
        a += b
        return a


if __name__ == '__main__':
    n = int(input())
    list = []
    for i in range(n):
        x, y, z = input().split(" ")
        list.append(Vector(int(x), int(y), int(z)))
    while True:
        try:
            command = input().split(" ")
            a = list[int(command[0])-1]
            b = list[int(command[1])-1]
            print(calc(a, b, command[2]))
        except EOFError:
            exit()
