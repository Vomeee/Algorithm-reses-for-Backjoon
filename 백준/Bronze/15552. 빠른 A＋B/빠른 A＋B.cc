#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int cases;
	cin >> cases; //input - number of testcases

	for (int i = 0; i < cases; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v.push_back(n1 + n2);
	}
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << '\n';
	}
}