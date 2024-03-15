N = int(input())
# 에라토스테네스의 체를 사용하여 소수 찾기
a = list(range(2, 1001, 1))
dividers = list(range(2, 33, 1))
for i in dividers:
    temp = 0
    for j in range(2, 1001 // i + 1):
        temp = i * j
        if temp in a:
            a.remove(temp)
            if temp in dividers:
                dividers.remove(temp)
        if temp > 1000:
            break

# 숫자 입력 받기
digits = list(map(int, input().split()))

# 입력 받은 숫자 중에서 소수인 것의 개수 세기
res = 0
for i in digits:
    if i in a:
        res += 1

print(res)
