def print_stars(n):
    print('*'*n)
def print_blanks(n):
     print(' ' * n, end='')

n = int(input())
for i in range (1,n,1):
    print_blanks(n - i)
    print_stars(2 * i - 1)
print_stars(2*n-1)
for i in range (n - 1, 0, -1):
    print_blanks(n - i)
    print_stars(2 * i - 1)