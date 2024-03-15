#include <stdio.h>

int main()
{

	int  yr;

	scanf("%d", &yr);

	if ((yr % 4) == 0)
	{
		if (yr % 400 == 100)
			printf("0");
		else if (yr % 400 == 200)
			printf("0");
		else if (yr % 400 == 300)
			printf("0");
		else
			printf("1");
	}
	else
		printf("0");
	

	return 0;
}