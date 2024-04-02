#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void BFS()
//재귀호출 필요없으니까 그냥 다 처리하자.
{
    int time_used[301][301]{};
    bool visited[301][301]{ false, };

    int max_index, initial_x, initial_y, obj_x, obj_y;
    cin >> max_index >> initial_x >> initial_y >> obj_x >> obj_y;

    pair<int, int> knight_initial{initial_x, initial_y}; //initialization of initial position of knight

    queue<pair<int, int>> q;

    int dx[8]{ -2, -2, -1, -1, 1, 1, 2, 2 };
    int dy[8]{ 1, -1, 2, -2, 2, -2, 1, -1 };

    time_used[initial_x][initial_y] = 0;
    visited[initial_x][initial_y] = true;
    q.push(knight_initial);

    if (initial_x == obj_x && initial_y == obj_y)
    {
        cout << 0 << endl;
        return;
    }

    while (!q.empty())
    {
        pair<int, int> curr_pair = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int next_x = curr_pair.first + dx[i], next_y = curr_pair.second + dy[i];

            if (next_x >= 0 && next_x < max_index && next_y >= 0 && next_y < max_index && !visited[next_x][next_y]) {
                visited[next_x][next_y] = true;
                q.push({ next_x, next_y });
                time_used[next_x][next_y] = time_used[curr_pair.first][curr_pair.second] + 1;
                    if ( next_x == obj_x && next_y == obj_y)
                    {
                        cout << time_used[next_x][next_y] << endl;
                        return;
                    }
                }
            }
        }

 }




int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        BFS();
    }

    return 0;
}
