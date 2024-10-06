#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> numbers; //const
vector<int> operator_counts(5);
vector<char> current_operators;

int min_value = INT_MAX; //saves minimum output 
int max_value = INT_MIN; //saves maximum output


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//Brute force...

	int count_of_numbers; //n
	cin >> count_of_numbers;

	for (int i = 0; i < count_of_numbers; i++)
	{
		int value;
		cin >> value;
		 
		numbers.push_back(value);
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> operator_counts[i];


		for (int j = 0; j < operator_counts[i]; j++)
		{
			if (i == 0)
			{
				current_operators.push_back('+');
			}
			else if (i == 1)
			{
				current_operators.push_back('-');
			}
			else if (i == 2)
			{
				current_operators.push_back('*');
			}
			else
			{
				current_operators.push_back('/');
			}
		}
		
	}

	sort(current_operators.begin(), current_operators.end());

	do {
		int output = numbers[0];

		for (int i = 0; i < numbers.size() - 1; i++)
		{
			if (current_operators[i] == '+')
			{
				output += numbers[i + 1];
			}
			else if (current_operators[i] == '-')
			{
				output -= numbers[i + 1];
			}
			else if (current_operators[i] == '*')
			{
				output *= numbers[i + 1];
			}
			else if (current_operators[i] == '/')
			{
				output /= numbers[i + 1];
			}
		}

		max_value = max(output, max_value);
		min_value = min(output, min_value);
	} while (next_permutation(current_operators.begin(), current_operators.end()));

	cout << max_value << '\n' << min_value;
}