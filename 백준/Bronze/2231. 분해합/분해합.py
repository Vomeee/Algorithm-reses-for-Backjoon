n = input()
N = int(n)
digits = []
counts = 0
constr = 0
temp = 0
for i in range(1,N):
    I = str(i)
    for j in I:
        digits.append(int(j))
    constr = i + sum(digits)
    if constr == N:
        counts += 1
        temp = i
        break
    digits = []
    
if counts != 0:
    print(temp)
else:
    print(0)