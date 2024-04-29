#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int func()
{
	int num_of_sizes; //합성할 페이지 개수
	cin >> num_of_sizes;
	int DP[501][501]{};//DP 테이블
	int sums[501]{};
	int currsum = 0;

	//초기 배열 초기화
	for (int i = 1; i <= num_of_sizes; i++)
	{
		int temp;
		cin >> temp;
		DP[i][i] = 0; //입력과 동시에 대각선부 초기화.
		sums[i] = currsum + temp; //합을 나타내는 배열도 초기화
		currsum += temp;
	}
	for (int i = 1; i <= num_of_sizes - 1; i++)
	{
		DP[i][i + 1] = sums[i + 1] - sums[i - 1];
	}
	int k = 2;
	for (int i = 1; i <= num_of_sizes - 2; i++)
	{
		
		for (int j = 1; j <= num_of_sizes - k; j++)
		{
			int min_value = INT_MAX;
			for (int p = 0; p < k; p++) //k = 2 -> 2회
			{
				int vvv = DP[j][j + p] + DP[j + p + 1][j + k] + sums[j + k] - sums[j - 1];
				if (vvv < min_value)
					min_value = vvv;
			}
			DP[j][j + k] = min_value;
		}
		k++;
	}

	return DP[1][num_of_sizes];

}

int main()
{
	int test_case_num;
	cin >> test_case_num;

	vector<int> res_vect; //답을 저장할 벡터
	for (int i = 0; i < test_case_num; i++)
	{
		res_vect.push_back(func());
	}

	for (int i : res_vect)
	{
		cout << i << '\n';
	}
}