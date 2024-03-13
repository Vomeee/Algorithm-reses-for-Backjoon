#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int* values = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> values[i]; 
    }// 오름차순 입력 values[0] = 1

    int res = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (k >= values[i])
        {
            res += k / values[i];
            k = k % values[i];
        }
    }

    cout << res;
}
