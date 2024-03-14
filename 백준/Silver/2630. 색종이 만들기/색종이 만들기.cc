#include <iostream>
using namespace std;

int whiteCount = 0;
int blueCount = 0;

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
        if (firstVal == 0) whiteCount++;
        else blueCount++;
    }
    else {
        int halfSize = size / 2;
        check(list, x1, y1, halfSize);
        check(list, x1, y1 + halfSize, halfSize);
        check(list, x1 + halfSize, y1, halfSize);
        check(list, x1 + halfSize, y1 + halfSize, halfSize);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int** list = new int* [n];
    for (int i = 0; i < n; i++) {
        list[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> list[i][j];
        }
    }

    check(list, 0, 0, n);

    cout << whiteCount << '\n' << blueCount;

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        delete[] list[i];
    }
    delete[] list;

    return 0;
}
