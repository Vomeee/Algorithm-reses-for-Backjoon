#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a struct for 3D coordinates
struct Coord {
    int x, y, z;
};

int BFS(int*** board, int m, int n, int h) {
    queue<Coord> q;
    int*** day = new int** [h];
    for (int i = 0; i < h; i++) {
        day[i] = new int* [n];
        for (int j = 0; j < n; j++) {
            day[i][j] = new int[m] {};
        }
    }

    // Initialize the queue with already ripe tomatoes
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (board[i][j][k] == 1) {
                    q.push({ k, j, i });
                    day[i][j][k] = 0;
                }
            }
        }
    }

    // Define directions in 3D: up, down, left, right, forward, backward
    int dx[6]{ 0, 0, -1, 1, 0, 0 };
    int dy[6]{ -1, 1, 0, 0, 0, 0 };
    int dz[6]{ 0, 0, 0, 0, -1, 1 };

    int max_day = 0;

    // Perform BFS
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            int nz = curr.z + dz[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n && 0 <= nz && nz < h && board[nz][ny][nx] == 0) {
                board[nz][ny][nx] = 1;
                q.push({ nx, ny, nz });
                day[nz][ny][nx] = day[curr.z][curr.y][curr.x] + 1;
                max_day = max(max_day, day[nz][ny][nx]);
            }
        }
    }

    // Clean up and check for any unripe tomatoes
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (board[i][j][k] == 0) {
                    // Free memory
                    for (int x = 0; x < h; x++) {
                        for (int y = 0; y < n; y++) {
                            delete[] day[x][y];
                        }
                        delete[] day[x];
                    }
                    delete[] day;
                    return -1; // Unripe tomato found
                }
            }
        }
    }

    // Free memory
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            delete[] day[i][j];
        }
        delete[] day[i];
    }
    delete[] day;

    return max_day;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m, n, h;
    cin >> m >> n >> h;

    int*** board = new int** [h];
    for (int i = 0; i < h; i++) {
        board[i] = new int* [n];
        for (int j = 0; j < n; j++) {
            board[i][j] = new int[m];
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
            }
        }
    }

    int result = BFS(board, m, n, h);
    cout << result << "\n";

    // Memory release
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            delete[] board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
