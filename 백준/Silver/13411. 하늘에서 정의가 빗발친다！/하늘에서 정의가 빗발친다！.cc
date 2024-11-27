#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<int, double>> vec;

	////////input number of enemy.
	int n;
	cin >> n;

	////////input information of robot.
	for (int i = 1; i <= n; i++)
	{
		int x, y, v;
		//x, y -> grid, x -> speed of projectile.
		cin >> x >> y >> v;

		//push to vec.
		double val = sqrt(x * x + y * y) / v;
		//squared value of time of projectile arrives.

		vec.push_back({ i, val });
	}

	std::sort(vec.begin(), vec.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
		if (a.second < b.second)
		{
			return true;
		}
		else if (a.second > b.second)
		{
			return false;
		}
		else
		{
			return a.first < b.first;
		}
	});

	for (auto it : vec)
	{
		cout << it.first << '\n';
	}


}