#1 -> 0
#2 - 7 -> 1 6
#8 - 19 -> 2 12
#18, 24....
N = int(input()) 

k = 1
i = 0
while(True):
    if(k >= N):
        break
    i += 1
    k += i * 6
    

print(i + 1)