#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int number_of_conference;
    cin >> number_of_conference;

    vector<pair<int, int>> cons(number_of_conference);

    for (int i = 0; i < number_of_conference; i++) {
        cin >> cons[i].first >> cons[i].second;
    }

    // 종료 시간을 기준으로 회의 정렬. 종료 시간이 같다면 시작 시간이 빠른 순으로 정렬
    sort(cons.begin(), cons.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int currentTime = 0;
    int count = 0;

    for (const auto &con : cons) {
        if (con.first >= currentTime) {
            currentTime = con.second;
            count++;
        }
    }

    cout << count;

    return 0;
}
