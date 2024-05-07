#include <iostream>
#include <vector>

using namespace std;


void func(const vector<vector<int>> &v, int curr, int* &mum, bool* &searched)
{
	for (int connected_node : v[curr])
	{
		if (!searched[connected_node])
		{
			//아직 부모가 확정되지 않은 노드.
			mum[connected_node] = curr;
			searched[connected_node] = true;
			func(v, connected_node, mum, searched);
		}
		
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n; //7
	cin >> n;
	int* mum = new int[n + 1] {0};
	bool* searched = new bool[n + 1] {false};

	vector<vector<int>> v(n + 1); //벡터, 각 연결노드 저장.

	for (int i = 0; i < n - 1; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1); //벡터 인덱스 0 안씀.
	}

	mum[1] = 0;
	searched[1] = true;
	func(v, 1, mum, searched);

	for (int i = 2; i <= n; i++)
	{
		cout << mum[i] << '\n';
	}
}