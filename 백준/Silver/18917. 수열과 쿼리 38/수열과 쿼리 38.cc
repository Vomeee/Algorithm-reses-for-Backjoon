#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m;
	cin >> m;

	long long sum = 0;
	int sum_xor = 0;

	for (int i = 0; i < m; i++)
	{
		int type;
		cin >> type;

		if (type == 3)
		{
			cout << sum << '\n';
		}
		else if (type == 4)
		{	
			cout << sum_xor << '\n';
		}
		else if (type == 1)
		{
			int value;
			cin >> value;
			sum += value;
			sum_xor ^= value;
		}
		else if (type == 2)
		{
			int value;
			cin >> value;

			sum -= value;
			sum_xor ^= value;
			
		}
	}
}