#include <iostream>
#include <vector>

using namespace std;

void preorder(const vector<pair<char, char>>& v, char curr) //A부터
{
	if (curr == '.') return; //terminal cond.
	cout << curr;
	preorder(v, v[curr - 65].first);
	preorder(v, v[curr - 65].second);
}

void inorder(const vector<pair<char, char>>& v, char curr)
{
	if (curr == '.') return; //terminal cond.
	inorder(v, v[curr - 65].first);
	cout << curr;
	inorder(v, v[curr - 65].second);
}

void postorder(const vector<pair<char, char>>& v, char curr)
{
	if (curr == '.') return; //terminal cond.
	postorder(v, v[curr - 65].first);
	postorder(v, v[curr - 65].second);
	cout << curr;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<char, char>> v(26);

	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;

		char c_left;
		cin >> c_left;
		v[c - 65].first = c_left;
		
		char c_right;
		cin >> c_right;
		v[c - 65].second = c_right;
	}

	preorder(v, 'A');
	cout << '\n';
	inorder(v, 'A');
	cout << '\n';
	postorder(v, 'A');
}