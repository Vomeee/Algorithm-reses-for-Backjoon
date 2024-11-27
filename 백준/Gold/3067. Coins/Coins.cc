#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_methods(const vector<int>& v, int obj)
{
	vector<vector<int>> DP(v.size(), vector<int>(obj + 1, 0));
	//////row 0 ~ v.size, col: 0 ~ 10000

	/////initialize DP.
	for (int i = 0; i <= obj; i++) {
		if (i % v[0] == 0) {
			DP[0][i] = 1;
		}
	}

	/////Execute for another elements.
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j <= obj; j++) {
			DP[i][j] = DP[i - 1][j]; 
			if (j >= v[i]) {
				DP[i][j] += DP[i][j - v[i]]; 
			}
		}
	}

	return DP[v.size() - 1][obj];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	///////input number of testcase.
	int ts;
	cin >> ts;

	///////for each testcase.
	for (int i = 0; i < ts; i++)
	{
		//////input number of type of coins.
		int n;
		cin >> n;

		vector<int> coins; //has value of coins.

		/////input coins value.
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			coins.push_back(temp);
		}

		/////input objective price.
		int obj;
		cin >> obj;

		/////sort coin value.
		sort(coins.begin(), coins.end());

		cout << count_methods(coins, obj) << '\n';
		
	}
}