#include <iostream>
#include <algorithm>
#include <numeric>

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
    int* digits = new int[5];
    for (int i = 0; i < 5; i++) {
        cin >> digits[i];
    }

    sorting(digits, 5);
    int avr = (digits[0] + digits[1] + digits[2] + digits[3] + digits[4]) / 5;
    cout << avr << endl << digits[2];

    // 동적으로 할당된 메모리 해제
    delete[] digits;

    return 0;
}
