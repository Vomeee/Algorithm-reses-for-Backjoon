#include <iostream>
using namespace std;
//2^30 > 10억

int code_to_int(char c) {
	if (0x41 <= c && c <= 0x5A) {
		return (c - 55);
	}
	else if (0x30 <= c && c <= 0x39) {
		return (c - '0');
	}
}

int main() {
	string n;
	int b;
	cin >> n >> b;
	

	long long res = 0;
	int sqr = 0;
	for (int j = 0; j < n.size(); j++) {
		int currentvalue = code_to_int(n[n.size() - j - 1]);
		int temp = currentvalue;
		
		for (int i = 0; i < sqr; i++) {
			temp *= b;
		}

		res += temp;
		
		
		sqr++;
	}
	
	cout << res;

}