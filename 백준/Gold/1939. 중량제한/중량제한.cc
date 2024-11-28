#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<pair<int,int>>> connections;
vector<bool> visited;
int n; //num of islands.
int start_point;
int end_point;

bool DFS(int val, int curr)
{
	/////terminal condition.
	if (curr == end_point)
	{
		return true;
	}
	else
	{
		visited[curr] = true;

		for (auto it : connections[curr])
		{
			if (it.second >= val && !visited[it.first]) //can go, not visited.
			{
				if (DFS(val, it.first))
					return true;
			}
		}

		return false;
	}
}

int binary_search_DFS(int start, int end)
{
	int result = 0;

	while (start <= end)
	{
		/////initialize visited.
		visited.assign(n + 1, false);

		int m = start + (end - start) / 2;

		if (DFS(m, start_point))
		{
			result = m;
			start = m + 1;
		}
		else
		{
			end = m - 1;
		}
	}

	return result;
}



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	/////input number of island, number of bridges.
	int m;
	cin >> n >> m;

	/////resize connections vector.
	connections.resize(n + 1);
	visited.resize(n + 1);

	/////input bridge's info.
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c; //a, b -> vertex, c -> limits of heaviness.

		connections[a].push_back({ b, c });
		connections[b].push_back({ a, c });
	}

	/////input start, end points.
	cin >> start_point >> end_point;
	
	///// BS -> DFS.
	cout << binary_search_DFS(0 ,INT_MAX); //start with max int.
}