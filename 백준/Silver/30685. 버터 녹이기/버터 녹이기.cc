#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<pair<int, int>> XH;

// 주어진 시간 내에 한 쌍이라도 만날 수 있는지 확인하는 함수
bool canMeet(int time, int n) {
    for (int i = 0; i < n - 1; i++) {
        int distance = XH[i + 1].first - XH[i].first;
        int range1 = min(time, XH[i].second);
        int range2 = min(time, XH[i + 1].second);

        // 한 쌍이라도 만나면 true 반환
        if (range1 + range2 >= distance) {
            return true;
        }
    }
    return false; // 모두 만나지 못할 때 false 반환
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp_X, tmp_H;
        cin >> tmp_X >> tmp_H;
        XH.push_back(make_pair(tmp_X, tmp_H / 2));
    }

    // 객체 위치 기준 정렬
    sort(XH.begin(), XH.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
        });

    int left = 0, right = INT_MAX;
    int min_time = -1;

    // 가능한 최소 시간을 찾기 위한 이분 탐색
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canMeet(mid, n)) {
            min_time = mid;
            right = mid - 1; // 더 작은 시간에서 가능한지 확인
        }
        else {
            left = mid + 1; // 더 큰 시간에서 확인
        }

        if (left >= INT_MAX) break;
    }

    if (min_time == -1) {
        cout << "forever";
    }
    else {
        cout << min_time - 1;
    }

    return 0;
}
