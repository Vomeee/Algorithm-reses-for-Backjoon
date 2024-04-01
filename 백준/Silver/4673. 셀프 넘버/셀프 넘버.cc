#include <iostream>
#include <vector>

using namespace std;

int func(int n) //function that calculate d(n).
{
	int res = n;
	while (n != 0)
	{
		int temp = n % 10;
		n = n / 10;
		res += temp;
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int digits[10001];
	for (int i = 1; i < 10001; i++)
	{
		digits[i] = i; //index 0 won't be used.
	}

	for (int i = 1; i < 9999; i++)
	{
		int current_index = func(i);
		while (current_index <= 10000)
		{
			if (digits[current_index] == 0) break; //terminal condition.

			
			digits[current_index] = 0;
			current_index = func(current_index); // nums those are not self N will be initalized by zero. 
		}
	}

	for (int i = 1; i < 10001; i++)
	{
		if (digits[i] != 0)
		{
			cout << digits[i] << '\n';
		}
	}

}