#include <stdio.h>

int main()
{

	int  a, b;

	int c;

	int hr, hrm;

	scanf("%d %d\n%d", &a, &b, &c);

	hr = c / 60;
	hrm = c % 60;

	a = a + hr;

	if ((b + hrm) >= 60)
	{
		a = a + 1;
		b = (b + hrm - 60);
	}
	else
		b = b + hrm;

	if (a >= 24)
		a = a - 24;

	printf("%d %d", a, b);

	return 0;
}