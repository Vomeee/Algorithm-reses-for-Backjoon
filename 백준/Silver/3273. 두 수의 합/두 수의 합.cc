#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int number_of_numbers;
	cin >> number_of_numbers;

	vector<int> v;

	for (int i = 0; i < number_of_numbers; i++)
	{
		int next_value;
		cin >> next_value;
		v.push_back(next_value);
	}
	sort(v.begin(), v.end());

	int x;
	cin >> x;

	auto it_left = v.begin();
	auto it_right = v.end() - 1;

	int count = 0;

	while (it_left != it_right)
	{
		if (*it_left + *it_right == x)
		{
			count++;
			it_right--;
		}
		else if(*it_left + *it_right > x)
		{
			it_right--;
		}
		else
		{
			it_left++;
		}
	}

	cout << count;

}