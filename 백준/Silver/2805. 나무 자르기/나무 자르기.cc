#include <iostream>
#include <algorithm> // std::sort를 사용하기 위해 추가

using namespace std;

bool dec(int* list, int size, int mid, int obj) {
    long long res = 0;
    for (int i = 0; i < size; i++) {
        if(list[i] >= mid)
        res += list[i] - mid;
    }
    return res >= obj;
}

int check(int* list, int size, int min, int max, int obj) {
    while (min < max) {
        int mid = min + (max - min + 1) / 2; // 중간 값 계산, 오버플로우 방지
        if (dec(list, size, mid, obj)) {
            // 조건을 만족하면, 최소 범위를 올린다
            min = mid;
        }
        else {
            // 조건을 만족하지 않으면, 최대 범위를 줄인다
            max = mid - 1;
        }
    }
    return min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; //나무의 수 = n, 필요한 길이 = m
    cin >> n >> m;
    int* N = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    } //나무의 길이 입력

    std::sort(N, N + n); // 배열 정렬

    int max = N[n - 1]; // 최대값은 정렬된 배열의 마지막 요소
    int min = 0; // 최소값을 1로 설정 (0으로 나누는 것을 피하기 위해)

    cout << check(N, n, min, max, m) << endl;

    delete[] N;
    return 0;
}
