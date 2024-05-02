#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int sd_between_2points(const vector<vector<int>> &distances, int n, int p1, int p2)
{
	vector<int> shortest_distance_from_start(n + 1, INT_MAX);
	vector<bool> searched(n + 1, false);

	int curr_p = p1;
	searched[p1] = true;
	shortest_distance_from_start[p1] = 0;


	while (true)
	{
		for (int i = 1; i <= n; i++)
		{
			if (distances[curr_p][i] != INT_MAX && !searched[i])
			{
				if (shortest_distance_from_start[curr_p] + distances[curr_p][i] <
					shortest_distance_from_start[i])
				{
					shortest_distance_from_start[i] =
						shortest_distance_from_start[curr_p] + distances[curr_p][i];
				}
			}
		} //거리 업데이트



		int next_min = INT_MAX;
		int next_index = -1;
		for (int i = 1; i <= n; i++)
		{

			if (!searched[i])
			{
				if (shortest_distance_from_start[i] < next_min) //탐색 안된건 intmax.
				{
					next_min = shortest_distance_from_start[i];
					next_index = i;
				}
			}
		} //현재 테이블 최솟값 찾기.

		if (next_index == -1)
		{
			break;
		} //종료조건. 변화가 없어서 탐색종료
		else
		{
			curr_p = next_index;
			searched[curr_p] = true;
		}

	}

	if (shortest_distance_from_start[p2] == INT_MAX)
	{
		return -1;
	}
	else
	{
		return shortest_distance_from_start[p2];
	}
}

int main()
{
	int n, e;

	cin >> n >> e;

	vector<vector<int>> distances(n + 1, vector<int>(n + 1, INT_MAX));
	

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		distances[a][b] = c;
		distances[b][a] = c;
	}

	int mid_p1, mid_p2;
	cin >> mid_p1 >> mid_p2;

	int ds1 = sd_between_2points(distances, n, 1, mid_p1);
	int ds2 = sd_between_2points(distances, n, 1, mid_p2);
	int d12 = sd_between_2points(distances, n, mid_p1, mid_p2);
	int d21 = sd_between_2points(distances, n, mid_p2, mid_p1);
	int d1e = sd_between_2points(distances, n, mid_p1, n);
	int d2e = sd_between_2points(distances, n, mid_p2, n);

	int path1;
	int path2;

	if (ds1 != -1 && ds2 != -1 && d12 != -1 && d21 != -1 && d1e != -1 && d2e != -1)
	{
		path1 = ds1 + d12 + d2e;
		path2 = ds2 + d21 + d1e;
		cout << min(path1, path2);
	}
	else
	{
		cout << -1;
	}

	return 0;

	
}