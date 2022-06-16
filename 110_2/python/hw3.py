import hashlib

input_file = open("CPPy_hw03.in","r")

for i in range (0,3):
    s = input_file.readline()
    s = (s+"109703037")
    code = hashlib.md5(s.encode("utf-8")).hexdigest()
    print(code)
    print('--------')
