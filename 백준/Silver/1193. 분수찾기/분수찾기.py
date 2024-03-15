X = int(input())

temp = 0
i = 1
while(True):
    if(temp < X <= temp + i):
        break
    temp += i
    i += 1
sumv = i + 1
v = X - temp

if(sumv % 2 == 0):
    print(f'{sumv -v}/{v}')
else :
    print(f'{v}/{sumv - v}')