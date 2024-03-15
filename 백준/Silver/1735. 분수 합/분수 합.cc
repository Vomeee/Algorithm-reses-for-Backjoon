#include <iostream>
#include <algorithm>

using namespace std;

int common_division(int n1, int n2) {
	int bv = max(n1, n2);
	int sv = min(n1, n2); // even if theyre same, its alright.... 
	if (bv % sv == 0) return sv;
	else if (sv == 0 && bv != 0) return bv;
	else {
		return common_division(bv % sv, sv);
	}

}

int common_multiple(int n1, int n2) {
	return n1 * n2 / common_division(n1, n2);
}

int main() {
	int m1, s1;
	int m2, s2;

	cin >> s1 >> m1;
	cin >> s2 >> m2;

	int res_m = m1 * m2;
	int res_s = s1 * m2 + s2 * m1;

	
	int temp = common_division(res_s, res_m); // 1

	res_m = res_m / temp;
	res_s = res_s / temp;

	cout << res_s << " " << res_m;

	return 0;



}