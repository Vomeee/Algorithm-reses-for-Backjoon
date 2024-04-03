#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int BFS(int** board, int col, int row) {
    queue<pair<int, int>> q;

    int** day = new int* [row];
    for (int i = 0; i < row; i++) {
        day[i] = new int[col] {0, };
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 1)
            {
                q.push({ i, j }); //it's pair...
                day[i][j] = 0;
            }
        }
    }

    int dx[4]{ -1,0,1,0 };
    int dy[4]{ 0,1,0,-1 };

    
    
    int max_day = 0;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
      
            if (0 <= ny && ny < row && 0 <= nx && nx < col && board[ny][nx] == 0)
            {
                board[ny][nx] = 1;
                q.push({ ny, nx });
                day[ny][nx] = day[curr.first][curr.second] + 1;
                max_day = max(max_day, day[ny][nx]);
            }
        }
    }


    for (int i = 0; i < row; i++)
    {
        delete[] day[i];
    }
    delete[] day;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 0)
            {
                return -1;
            }
        }
    }

    return max_day;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int row, col;
    cin >> col >> row;

    int** board = new int* [row];
    for (int i = 0; i < row; i++) {
        board[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
        }
    } // initialization. for tomato board.

    
    int result = BFS(board, col, row);
    cout << result << "\n";

    // 메모리 해제
    for (int i = 0; i < row; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
