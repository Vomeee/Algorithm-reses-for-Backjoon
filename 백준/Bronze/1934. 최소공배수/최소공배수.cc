#include <iostream>
#include <algorithm>

using namespace std;

int common_division(int n1, int n2) {
	int bv = max(n1, n2);
	int sv = min(n1, n2); // else if theyre same, its alright.... 
	if (bv % sv == 0) return sv;
	else if (sv == 0 && bv != 0) return bv;
	else {
		return common_division(bv % sv , sv);
	}

}

int common_multiple(int n1, int n2) {
	return n1 * n2 / common_division(n1, n2);
}

int main() {
	int n;
	cin >> n;

	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < n; i++) {
		cout << common_multiple(a[i], b[i]) << endl;
	}

	return 0;
}