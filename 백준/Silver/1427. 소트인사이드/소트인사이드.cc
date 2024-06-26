#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;

	while (n > 0)
	{
		v.push_back(n % 10);
		n /= 10;
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i : v)
	{
		cout << i;
	}

	return 0;
	
}