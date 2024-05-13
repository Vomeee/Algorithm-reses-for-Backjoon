#include <iostream>

using namespace std;

//const int nums[8]{ 1,2,3,4,5,6,7,8 };
int res[7]{ 0 };

void func(int start, int end, int current_index, int final_index)
{
	for (int i = start; i <= end; i++)
	{
		res[current_index] = i; //1.

		if (current_index == final_index)
		{
			for (int j = 0; j <= final_index; j++)
			{
				cout << res[j] << " ";
			}
				
			cout << '\n';
		}
			else
			{
				func(start, end,  current_index + 1, final_index);
			}
		
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int start = 1;
	int end = n;
	int curr_index = 0;
	int end_index = m - 1;
	func(start, end,  curr_index, end_index);
}