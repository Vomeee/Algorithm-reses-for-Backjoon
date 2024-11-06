#include <iostream>
#include <vector>

using namespace std;

int divide(int n)
{
	int res = 0;
	int init = n;

	while (init >= 0)
	{
		res += (init / 2 + 1);
		init -= 3;
	}

	return res;
	
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> res;


	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		res.push_back(divide(temp));
	}

	for (int i : res)
	{
		cout << i << '\n';
	}
}