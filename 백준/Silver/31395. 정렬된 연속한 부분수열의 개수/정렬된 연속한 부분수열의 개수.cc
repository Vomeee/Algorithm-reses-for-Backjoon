#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long> v;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;

		v.push_back(temp);
	}

	long long sum = 0;
	long long count = 0;
	long long num_before = 0;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it >= num_before)
		{
			count++;			
		}
		else
		{
			count = 1;			
		}
		sum += count;
		num_before = *it;		
	}

	cout << sum;
}