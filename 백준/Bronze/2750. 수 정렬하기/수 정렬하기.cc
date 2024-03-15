#include <iostream>
#include <algorithm>

using namespace std;

void sorting(int* digits, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (digits[j] > digits[j + 1]) {
                swap(digits[j], digits[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    cin >> n;
    int* digits = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    sorting(digits, n);

    for (int i = 0; i < n; i++) {
        cout << digits[i] << " ";
        cout << endl;
    }
    

    // 동적으로 할당된 메모리 해제
    delete[] digits;

    return 0;
}
