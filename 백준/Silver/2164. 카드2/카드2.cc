#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n; 
	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	} //initialization of first queue.

	while (q.size() != 1)
	{
		q.pop();
		int next = q.front();
		q.pop();
		q.push(next);

	}

	cout << q.front();
}