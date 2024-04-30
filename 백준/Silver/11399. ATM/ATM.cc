#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int number_of_people;
	cin >> number_of_people;

	vector<int> time_taken;

	for (int i = 0; i < number_of_people; i++)
	{
		int p;
		cin >> p;
		time_taken.push_back(p);
	}

	sort(time_taken.begin(), time_taken.end());

	int sum = 0, total_time = 0;

	for (int i = 0; i < number_of_people; i++)
	{
		sum += time_taken[i];
		total_time += sum;
	}

	cout << total_time;

	return 0;
}