#include <iostream>
#include <deque>  // deque 사용

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    deque<pair<int, int>>s; // deque 사용

    int n;
    cin >> n;

    int total_score = 0;

    for (int i = 0; i < n; i++)
    {
        int type, score, time;
        cin >> type;

        if (type == 1) {
            cin >> score >> time;
            s.push_back(make_pair(score, time)); // 새로운 과제
        }

        if (!s.empty()) {
            auto last = --s.end();
            (last->second)--; // 시간 줄이기

            if (last->second == 0) {
                total_score += last->first;
                s.erase(last); // 0이 되면 삭제
            }
        }
    }

    cout << total_score << endl;
    return 0;
}
