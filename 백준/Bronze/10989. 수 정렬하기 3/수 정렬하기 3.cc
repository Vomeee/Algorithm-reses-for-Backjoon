#include <iostream>

using namespace std;

int num_count[10001]; // 최대 10000의 수를 카운팅하기 위한 배열

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int temp;

    // 입력받은 수 카운팅
    for (int i = 0; i < n; i++) {
        cin >> temp;
        num_count[temp]++;
    }

    // 카운팅된 수를 순서대로 출력
    for (int i = 1; i <= 10000; i++) {
        while (num_count[i] > 0) {  // 현재 숫자가 더 이상 없을 때까지 반복
            cout << i << '\n';
            num_count[i]--;
        }
    }

    return 0;
}
