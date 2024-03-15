#include <iostream>
using namespace std;

int main() {
	int arr[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	int mx = 1, my = 1;

	int temp = arr[0][0];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] > temp) {
				temp = arr[i][j];
				mx = i + 1; my = j + 1;
			}
		}
	}

	cout << temp << endl << mx << " " << my;
}

