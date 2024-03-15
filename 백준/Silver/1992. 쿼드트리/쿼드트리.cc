#include <iostream>
#include <string>
#include <limits>
using namespace std;

void check(int** list, int x1, int y1, int size) {
    bool isAllSame = true;
    int firstVal = list[x1][y1];

    for (int i = x1; i < x1 + size; i++) {
        for (int j = y1; j < y1 + size; j++) {
            if (list[i][j] != firstVal) {
                isAllSame = false;
                break;
            }
        }
        if (!isAllSame) break;
    }

    if (isAllSame) {
        cout << firstVal;
    }
    else {
        cout << "(";
        int halfSize = size / 2;
        check(list, x1, y1, halfSize);
        check(list, x1, y1 + halfSize, halfSize);
        check(list, x1 + halfSize, y1, halfSize);
        check(list, x1 + halfSize, y1 + halfSize, halfSize);
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼 비우기

    int** list = new int* [n];
    for (int i = 0; i < n; i++) {
        list[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        string digitline;
        getline(cin, digitline);
        for (int j = 0; j < n; j++) {
            list[i][j] = digitline[j] - '0';
        }
    }

    check(list, 0, 0, n);

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        delete[] list[i];
    }
    delete[] list;

    return 0;
}
