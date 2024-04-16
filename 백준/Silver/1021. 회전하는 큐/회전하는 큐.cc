#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> index(n);
    for (int i = 0; i < n; i++) {
        index[i] = i + 1;
    }

    vector<int> M(m);
    for (int i = 0; i < m; i++) {
        cin >> M[i];
    }

    int totalcount = 0;
    for (int target : M) {
        auto target_pos = find(index.begin(), index.end(), target);
        int right_dist = distance(index.begin(), target_pos);
        int left_dist = index.size() - right_dist;

        if (right_dist <= left_dist) {
            totalcount += right_dist;
            rotate(index.begin(), target_pos, index.end());
        }
        else {
            totalcount += left_dist;
            rotate(index.rbegin(), index.rend() - right_dist, index.rend());
        }
        index.erase(index.begin()); // 맨 앞 요소 제거
    }

    cout << totalcount << endl;
    return 0;
}
