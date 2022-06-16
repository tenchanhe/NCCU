class shape:
    def __init__(self,ttype,perimeter,area):
        self.ttype = ttype
        self.perimeter = perimeter
        self.area = area

    def __eq__(self,other):
        if self.area == other.area:
            return True
        return False

    def __gt__(self,other):
        if self.perimeter > other.perimeter:
            return True
        return False

    def __lt__(self,other):
        if self.perimeter < other.perimeter:
            return True
        return False

    def __add__(self,other):
        if self.ttype == 'circle':
            return self.area + other.area
        
        elif self.ttype == 'square':
            return self.perimeter + other.perimeter
        
        elif self.ttype == 'triangle':
            return self.area + other.area + self.perimeter + other.perimeter

class column:
    def __init__(self,ttype,perimeter,area,height):
        self.ttype = ttype
        self.perimeter = perimeter
        self.area = area
        self.height = height
    
    def __eq__(self,other):
#        print((self.area * self.height), (other.area * other.height))
        if (self.area * self.height) == (other.area * other.height):
            return True
        return False

    def __gt__(self,other):
#        print((self.perimeter * self.height),(other.perimeter * other.height))
        if (self.perimeter * self.height) > (other.perimeter * other.height):
            return True
        return False

    def __lt__(self,other):
        if (self.perimeter * self.height) < (other.perimeter * other.height):
            return True
        return False

    def __add__(self,other):
        if self.ttype == 'circleColumn':
            return (self.perimeter * self.height) + (other.perimeter * other.height)
        
        elif self.ttype == 'squareColumn':
            return (self.area * self.height) + (other.area * other.height)

        elif self.ttype == 'triangleColumn':
            return (self.perimeter * self.height) + (other.perimeter * other.height) + (self.area * self.height) + (other.area * other.height)

if __name__ == '__main__':
    while True:
        try:
            first = input().split()
            cmd = input()
            second = input().split()
            
            if len(first)==3 and len(second)==3:
                a = shape(first[0],int(first[1]),int(first[2]))
                b = shape(first[0],int(second[1]),int(second[2]))

            elif len(first)==4 and len(second)==4:
                a = column(first[0],int(first[1]),int(first[2]),int(first[3]))
                b = column(first[0],int(second[1]),int(second[2]),int(second[3]))
            
            if cmd == '==':
                print(a == b)

            elif cmd == '>':
                print(a > b)

            elif cmd == '<':
                print(a < b)

            elif cmd == '+':
                print(a + b)

        except EOFError:
            exit()
