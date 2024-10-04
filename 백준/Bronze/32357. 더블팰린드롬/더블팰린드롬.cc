#include <iostream>
#include <deque>

using namespace std;

bool isPalindrome(string s) //s is already even alphabets.
{
	bool is_palindrome = true;

	int string_length = s.length();

	for (int i = 0; i < string_length / 2; i++) //length = index++
	{
		if (s[i] != s[string_length - i - 1])
		{
			is_palindrome = false;
			break;
		}
	}

	return is_palindrome;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int number_of_string;

	cin >> number_of_string;

	deque<string> strings;

	for (int i = 0; i < number_of_string; i++)
	{
		string s;

		cin >> s;

		strings.push_back(s);
	}

	int number_of_palindromes = 0;

	for (auto it = strings.begin(); it < strings.end(); it++)
	{
		if (isPalindrome(*it))
		{
			number_of_palindromes++;
		}
	}

	cout << (number_of_palindromes * (number_of_palindromes - 1));
}

