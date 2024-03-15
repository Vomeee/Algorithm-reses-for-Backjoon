#include <iostream>
using namespace std;

int countM1 = 0;
int count0 = 0;
int count1 = 0;

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
        if (firstVal == -1) countM1++;
        else if (firstVal == 0) count0++;
        else count1++;
    }
    else {
        int size1 = size / 3;
        int size2 = size / 3 * 2;
        check(list, x1, y1, size1);
        check(list, x1, y1 + size1, size1);
        check(list, x1 + size1, y1, size1);
        check(list, x1 + size1, y1 + size1, size1);
        check(list, x1, y1 + size2, size1);
        check(list, x1 + size2, y1, size1);
        check(list, x1 + size2, y1 + size1, size1);
        check(list, x1 + size1, y1 + size2, size1);
        check(list, x1 + size2, y1 + size2, size1);
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

    cout << countM1 << '\n' << count0 << "\n" << count1;

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        delete[] list[i];
    }
    delete[] list;

    return 0;
}
