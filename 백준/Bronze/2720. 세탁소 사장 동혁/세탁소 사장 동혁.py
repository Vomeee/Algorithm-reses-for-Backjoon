Quarter = 25
Dime = 10
Nickel = 5
Penny = 1

T = int(input())

test_case = []
for i in range(T):
    test_case.append(int(input()))

output = []
for i in test_case:
    i1 = i // Quarter
    i2 = i % Quarter // Dime
    i3 = (i - (i1 * Quarter) - (i2 * Dime)) // Nickel
    i4 = i % Nickel
    output_i = [i1, i2, i3, i4]
    output.append(output_i)
    
for i in range(T):
    for j in range(4):
        print(output[i][j], end = ' ')
    print()