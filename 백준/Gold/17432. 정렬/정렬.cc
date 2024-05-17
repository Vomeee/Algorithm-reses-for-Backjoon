#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int N; //5
		int count; //0
		cin >> N >> count;

		vector<int> index_vector;
		vector<int> res_vector(N);
		
		int curr = N - 1;
		while (true)
		{
			if (curr < count)
			{
				index_vector.push_back(curr); //index가 들어감...
				count -= curr; //10 - 4
			}
			else
			{
				index_vector.push_back(count);
				break;
			}
			
			curr--;			
		}

		int changed_value = N;
		for (int i : index_vector)
		{
			res_vector[N - i - 1] = changed_value;
			changed_value--;
		}
	
		int res_index = 0;
		for (int i = 1; i != changed_value + 1;)
		{
			if (res_vector[res_index] == NULL)
			{
				res_vector[res_index] = i;
				i++;
			}

			res_index++;
			
		} //vector 완성

		for (int i : res_vector)
			cout << i << ' ';

		cout << '\n';

	}
}