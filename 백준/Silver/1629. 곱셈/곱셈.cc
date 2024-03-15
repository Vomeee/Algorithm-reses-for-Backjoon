#include <iostream>
using namespace std;

int power(int a, int b, int c) {
    if (b == 0) return 1; // b가 0일 때의 기본 케이스 추가
    if (b % 2 == 0) {
        long long half = power(a, b / 2, c); // 재귀 호출을 통한 분할 정복
        return (half * half) % c; // 중간 결과의 제곱
    }
    else {
        long long half = power(a, b / 2, c); // b가 홀수일 경우, b-1을 처리하고 a를 한 번 더 곱함
        return ((half * half) % c * a % c) % c; // 중간 결과의 제곱에 a를 곱함
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num, multiplier, divider;
    cin >> num >> multiplier >> divider;

    cout << power(num, multiplier, divider);

    return 0;
}
