#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int number_of_cases;
	cin >> number_of_cases;

	vector<int> features;

	for (int i = 0; i < number_of_cases; i++)
	{
		int temp;
		cin >> temp;
		features.push_back(temp);
	}

	sort(features.begin(), features.end());

	int closest_result = INT_MAX;
	auto start = features.begin();
	auto end = features.end() - 1;

	int num1 = 0, num2 = 0;

	while (start < end)
	{
		int current_sum = *start + *end;
		if (abs(current_sum) < abs(closest_result))
		{
			closest_result = current_sum;
			num1 = *start;
			num2 = *end;
		}
		if (current_sum < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << num1 << " " << num2;
	return 0;
}
