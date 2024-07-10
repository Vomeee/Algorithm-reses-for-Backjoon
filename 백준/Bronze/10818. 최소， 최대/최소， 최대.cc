#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		min = std::min(min, temp);
		max = std::max(max, temp);
		
	}

	cout << min << ' ' << max;


}