n, m = map(int, input().split())
cards = list(map(int,input().split()))
temp = 0
for i in range(n - 2):
    for j in range(i + 1, n - 1, 1 ):
        for k in range(j + 1, n, 1 ):
            res = cards[i] + cards[j] + cards[k]
            if res > temp:
                if res <= m:
                    temp = res
print(temp)
    