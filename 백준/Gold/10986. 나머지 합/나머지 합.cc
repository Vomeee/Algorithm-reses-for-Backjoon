#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num_count, divider;
    cin >> num_count >> divider;

    long* nums = new long[num_count];

    for (int i = 0; i < num_count; i++) {
        cin >> nums[i];
    }

    long long res = 0; // 결과값이 클 수 있으므로 long long 사용

    int* remainder_counter = new int[divider] {}; // 나머지의 범위는 0부터 divider-1
    long long temp = 0;
    remainder_counter[0] = 1; // 나머지가 0인 경우를 위해 초기값 설정

    for (int i = 0; i < num_count; i++) {
        temp += nums[i];
        int re = (temp % divider + divider) % divider; // 음수 나머지 처리

        res += remainder_counter[re]; // 같은 나머지를 가진 누적합의 개수를 결과에 추가

        remainder_counter[re]++;
    }

    cout << res;

    delete[] nums;
    delete[] remainder_counter;

    return 0;
}
