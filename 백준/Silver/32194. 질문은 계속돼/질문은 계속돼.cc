#include <iostream>
#include <vector>

using namespace std;

vector<int> v; //has accumulated value for each index.

void check_and_print(int type, int start, int end)
{
	///////////////check current questions answer and push_back new value for vector.

	/////check.
	if (type == 1) //check consecutive 'yes'.
	{
		if (v[end] - v[start - 1] == (end - start + 1)) //all yes. ans == yes.
		{
			cout << "Yes" << '\n';
			v.push_back(v[v.size() - 1] + 1);
		}
		else //not all yes, new value is 'no'.
		{
			cout << "No" << '\n';
			v.push_back(v[v.size() - 1] + 2);
		}
	}
	else if (type == 2) //check consecutive 'no'.
	{
		if (v[end] - v[start - 1] == 2 * (end - start + 1)) //all No. ans == yes.
		{
			cout << "Yes" << '\n';
			v.push_back(v[v.size() - 1] + 1);
		}
		else //not all no, new value is 'no'.
		{
			cout << "No" << '\n';
			v.push_back(v[v.size() - 1] + 2);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	//////initial source of vector.
	v.push_back(0); //overflow preventing.
	v.push_back(1); //first answer for q.

	//////input of question counts.
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int type, x, y;
		cin >> type >> x >> y;

		check_and_print(type, x, y);
	}
}