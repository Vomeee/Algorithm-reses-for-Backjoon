#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int case_num;
	cin >> case_num;

	vector<pair<int, int>> v;
	v.push_back(make_pair(1, 0));
	v.push_back(make_pair(0, 1));

	for (int i = 2; i <= 40; i++)
	{
		int count_zero = v[i - 2].first + v[i - 1].first;
		int count_one = v[i - 2].second + v[i - 1].second;
		v.push_back(make_pair(count_zero, count_one));
	}

	vector<int> c;

	for (int i = 0; i < case_num; i++)
	{
		int n;
		cin >> n;

		c.push_back(n);
	}
	for (int i : c)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	

}