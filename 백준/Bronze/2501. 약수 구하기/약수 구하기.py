N, K = map(int, input().split())

divisors = []
for i in range(1, N//2+1, 1):
    if (N % i == 0):
        divisors.append(i)
divisors.append(N)
        
if(K > len(divisors)):
    print(0)
else:
    print(divisors[K -1])
