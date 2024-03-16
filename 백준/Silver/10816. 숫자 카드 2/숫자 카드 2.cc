#include <iostream>
#include <algorithm> // std::sort를 사용하기 위해 추가

using namespace std;

// lower_bound 함수 구현
int lower_bound(int* list, int start, int end, int obj) {
    while (start < end) {
        int mid = (start + end) / 2;
        if (list[mid] < obj) start = mid + 1;
        else end = mid;
    }
    return start;
}

// upper_bound 함수 구현
int upper_bound(int* list, int start, int end, int obj) {
    while (start < end) {
        int mid = (start + end) / 2;
        if (list[mid] <= obj) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int* N = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    // std::sort를 사용하여 배열 N을 정렬합니다.
    std::sort(N, N + n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        // upper_bound와 lower_bound의 차이를 출력하여 요소의 개수를 찾습니다.
        cout << upper_bound(N, 0, n, x) - lower_bound(N, 0, n, x) << ' ';
    }

    delete[] N;

    return 0;
}
