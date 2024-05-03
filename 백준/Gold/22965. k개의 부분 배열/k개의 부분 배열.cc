#include <iostream>
#include <vector>

using namespace std;

bool is_one(vector<int> v)
{
	//이미 오름차순
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool is_two(vector<int> v)
{
	int ss = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			ss++;
		}
	}

	if (ss == 1 && v[0] > v[v.size() - 1])
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	int n;
	cin >> n;

	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		nums.push_back(temp);
	}

	if (is_one(nums))
	{
		cout << 1;
	}
	else if (is_two(nums))
	{
		cout << 2;
	}
	else
	{
		cout << 3;
	}
	return 0;
}