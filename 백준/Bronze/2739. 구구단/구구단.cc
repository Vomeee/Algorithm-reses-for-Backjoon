#include <stdio.h>

int main()
{
    int a, i;
	scanf("%d", &a);

	for (i = 0; i < 9; i++)
	{
		printf("%d * %d = %d\n", a, i + 1,a*(i+1));
	}
}