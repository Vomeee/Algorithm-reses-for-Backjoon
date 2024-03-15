#include <iostream>
using namespace std;

int** array_return(int** &array, int row, int col) {

	for (int i = 0; i < row; i++) {
		array[i] = new int[col];

		for (int j = 0; j < col; j++) {
			cin >> array[i][j];
		}
	}

	return array;
}

int main() {
	int n, m;
	cin >> n >> m;

	int** arr1 = new int* [n];
	int** arr2 = new int* [n];
	int** rarr = new int* [n];
	
	for (int i = 0; i < n; i++) {
		rarr[i] = new int[m];
	}
	
	arr1 = array_return(arr1, n, m);
	arr2 = array_return(arr2, n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			rarr[i][j] = arr1[i][j] + arr2[i][j];

			cout << rarr[i][j] << " ";
		}

		cout << endl;
	}
}
