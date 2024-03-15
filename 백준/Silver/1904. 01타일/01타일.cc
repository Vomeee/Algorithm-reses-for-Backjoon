#include <iostream>

using namespace std;

int tiling(int n)
{
	int* N = new int[n];
	N[0] = 1;
	N[1] = 2;
	for (int i = 2; i < n; i++) {
		N[i] = (N[i - 1] + N[i - 2]) % 15746;
	}
	return N[n - 1];
}
/*n = 8
i) 맨 앞이 00
	n = 6
ii) 1
	n = 7
*/

int main() {
	int n;
	cin >> n;
	cout << tiling(n);
}