#include <iostream>
#include <algorithm> // std::swap을 사용하기 위해 추가

using namespace std;

// 이진 탐색 함수
int binarySearch(int* list, int start, int end, int obj) {
    while (start <= end) {
        int m = (start + end) / 2;
        if (list[m] == obj) return 1; // 요소를 찾은 경우
        else if (list[m] > obj) end = m - 1;
        else start = m + 1;
    }
    return 0; // 요소를 찾지 못한 경우
}

// 퀵소트 함수
void quickSort(int* list, int start, int end) {
    if (start >= end) return; // 기저 조건

    int pivot = list[(start + end) / 2];
    int left = start;
    int right = end;

    while (left <= right) {
        while (list[left] < pivot) left++;
        while (list[right] > pivot) right--;

        if (left <= right) {
            std::swap(list[left], list[right]);
            left++;
            right--;
        }
    }

    quickSort(list, start, right);
    quickSort(list, left, end);
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

    quickSort(N, 0, n - 1);

    int m;
    cin >> m;
    int* M = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> M[i];
        cout << binarySearch(N, 0, n - 1, M[i]) << '\n';
    }

    delete[] N;
    delete[] M;

    return 0;
}
