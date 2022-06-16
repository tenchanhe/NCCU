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
