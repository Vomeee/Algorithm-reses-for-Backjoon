#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int>> sizes; //각 행렬의 size들.
int DP[501][501]{};

int main()
{
	int num_of_matrix;
	cin >> num_of_matrix;
	sizes.push_back(make_pair(0, 0)); //vector 인덱스도 1부터, 똥값 사용.

	for (int i = 0; i < num_of_matrix; i++)
	{
		int m, n;
		cin >> m >> n;
		sizes.push_back(make_pair(m, n)); //입력 하고, 페어상태로 벡터에 집어넣기.
	}

	for (int i = 1; i <= num_of_matrix; i++)
	{
		DP[i][i] = 0; //자기자신이랑 곱할수는 없으니 0.
	}

	int curr_distance = 1; //깨끗하게 쓰고 싶다.
	for (int i = 1; i <= num_of_matrix - 1 ; i++) //대각선 한줄씩 채우니까, n-1 회 반복한다.
	{
		for (int x = 1; x <= num_of_matrix - curr_distance; x++)
		{
			int temp = INT_MAX;

			for (int k = 0; k < curr_distance; k++)
			{
				int curr_value = DP[x][x + k] + DP[x + k + 1][x + curr_distance]
					+ sizes[x].first * sizes[x + k].second * sizes[x + curr_distance].second;
				if (curr_value < temp)
				{
					temp = curr_value;
				}
			}
			DP[x][x + curr_distance] = temp;
		}
		curr_distance++;
	}
	cout << DP[1][num_of_matrix];
}