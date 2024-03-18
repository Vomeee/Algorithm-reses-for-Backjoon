#include <iostream>
#include <algorithm>

using namespace std;

bool dec(int* list, int size, int mid, int obj) { //obj는 공유기 갯수
    int count = 1;
    int lastX = list[0];

    for (int i = 1; i < size; i++)
    {
        if (list[i] - lastX >= mid)
        {
            count++; 
            lastX = list[i];
        }
    }

    return count >= obj;
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

    int n, c; //나무의 수 = n, 공유기의 개수 == c
    cin >> n >> c;
    int* N = new int[n]; // 집의 '좌표' -> N

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    } //집의 좌표

    std::sort(N, N + n); // 배열 정렬

    int max = N[n - 1] - N[0]; // 간격 개수에 따른 최대값 설정 
    int min = 1; // 최소값을 1로 설정 (0으로 나누는 것을 피하기 위해)

    if (c == 2)
    {
        cout << N[n - 1] - N[0];
    }
    else
    {
        cout << check(N, n, min, max, c) << endl;
    }
    delete[] N;
    return 0;
}
