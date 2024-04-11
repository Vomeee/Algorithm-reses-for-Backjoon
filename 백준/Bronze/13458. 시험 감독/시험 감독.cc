#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> num_of_testers;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		num_of_testers.push_back(temp);
	}
	int b, c;
	cin >> b >> c;
	long long res = 0;
	for (int i : num_of_testers)
	{
		res++; //반드시 한 명은 있고.
		if (i > b)
		{
			if ((i - b) % c == 0)
				res += (i - b) / c;
			else
				res += (i - b) / c + 1;
		}
	}

	cout << res;
}