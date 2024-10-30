#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;

int main() 
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		B.push_back(temp);
	}

	int as = 0;
	int bs = 0;
	int max_find = 100;

	vector<int> res;

	while (max_find != 0)
	{
		vector<int> max_index_a;
		int count_a = 0;
		for (int i = as; i < A.size(); i++) {
			if (A[i] == max_find)
			{
				count_a++;
				max_index_a.push_back(i);
			}
		}
		vector<int> max_index_b;
		int count_b = 0;
		for (int i = bs; i < B.size(); i++) {
			if (B[i] == max_find)
			{
				count_b++;
				max_index_b.push_back(i);
			}
		}

		if (max_index_a.size() == 0 || max_index_b.size() == 0)
		{
			max_find--;
		}
		else
		{
			int index_count = min(count_a, count_b);
			for (int i = 0; i < index_count; i++)
			{
				res.push_back(max_find);
			}
			as = max_index_a[index_count - 1] + 1;
			bs = max_index_b[index_count - 1] + 1;
			max_find--;
		}

	}

	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
}