#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int maze[101][101];
bool visited[101][101] = { false }; // 초기화 부분 수정

int dx[4] = { 1, 0, -1, 0 }; // 상하좌우 이동을 위한 x 방향
int dy[4] = { 0, 1, 0, -1 }; // 상하좌우 이동을 위한 y 방향

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int row, col;
    cin >> row >> col;

    for (int i = 1; i <= row; i++) {
        string numline;
        cin >> numline;
        for (int j = 1; j <= col; j++) {
            maze[i][j] = numline[j - 1] - '0'; // 문자를 정수로 변환
        }
    }

    queue<pair<int, int>> q;
    queue<int> level; // 이동 횟수를 저장할 큐
    visited[1][1] = true;
    q.push({ 1, 1 });
    level.push(1); // 시작점의 레벨은 1

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int cur_level = level.front();
        q.pop();
        level.pop();

        if (x == row && y == col) { // 목표 도달 시 출력 후 종료
            cout << cur_level << "\n";
            break;
        }

        for (int i = 0; i < 4; i++) { // 상하좌우 탐색
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= row && ny >= 1 && ny <= col && maze[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                level.push(cur_level + 1); // 다음 레벨은 현재 레벨 + 1
            }
        }
    }

    return 0;
}
