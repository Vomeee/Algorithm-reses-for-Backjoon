#include <iostream>

using namespace std;

int list[201]; //index 0 not be used.

int node_find(int num)
{
	if (list[num] == num) return num;
	return list[num] = node_find(list[num]);
}

void node_union(int row, int col)
{
	list[node_find(col)] = node_find(row);
}

bool connection_find(int a, int b)
{
	return node_find(b) == node_find(a);
}




int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n_city; // <= 200
	int n_plan; // <= 1000

	cin >> n_city >> n_plan;

	for (int i = 1; i <= n_city; i++)
	{
		list[i] = i; // 초기화
	}

	for (int i = 1; i <= n_city; i++)
	{
		for (int j = 1; j <= n_city; j++)
		{
			int temp;
			cin >> temp;

			if (temp == 1 && j > i)
			{
				node_union(i, j);
			}
		}
	}

	int* plans = new int[n_plan];
	for (int i = 0; i < n_plan; i++)
	{
		cin >> plans[i];
	} //plan input.

	for (int i = 0; i < n_plan - 1; i++)
	{
		if (!connection_find(plans[i], plans[i + 1]))
		{
			cout << "NO"; return 0;
		}
	}

	cout << "YES";
}