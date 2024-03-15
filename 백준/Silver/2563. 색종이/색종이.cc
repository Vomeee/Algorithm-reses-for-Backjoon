#include <iostream>
using namespace std;

void return_sqr(int** sqr, int x, int y);

int main() {
    int count;
    cin >> count;

    int**sqr = new int*[100];

    for (int i = 0; i < 100; i++) {
        sqr[i] = new int[100];
        fill(sqr[i], sqr[i] + 100, 0);
    }
    for (int i = 0; i < count; i++) {
        int x, y;
        cin >> x >> y;
        return_sqr(reinterpret_cast<int**>(sqr), x, y);
    }

    int sum = 0; 
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (sqr[i][j] == 1) sum += 1;
        }
    }

    cout << sum;
    

    return 0;
}

void return_sqr(int** sqr, int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sqr[x + i][y + j] = 1;
        }
    }
}
