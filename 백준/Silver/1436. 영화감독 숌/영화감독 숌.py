def IsApocalypse(str_n):
    for i in range(len(str_n) - 2):
        if str_n[i] + str_n[i+1] + str_n[i+2] == '666':
            return True
    return False

n = int(input())
digit = 666
count = 0
res = 0

while count < n:
    if IsApocalypse(str(digit)):
        count += 1
        res = digit
    
    digit += 1

print(res)
