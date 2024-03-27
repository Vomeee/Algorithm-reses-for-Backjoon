#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int** graph, int max_row, int max_col, bool** visited, int current_row, int current_col) {
    visited[current_row][current_col] = true;

    // 상, 하, 좌, 우 탐색
    int row_directions[4] = { -1, 1, 0, 0 };
    int col_directions[4] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; ++i) {
        int next_row = current_row + row_directions[i];
        int next_col = current_col + col_directions[i];

        if (next_row >= 1 && next_row <= max_row && next_col >= 1 && next_col <= max_col &&
            graph[next_row][next_col] == 1 && !visited[next_row][next_col]) {
            DFS(graph, max_row, max_col, visited, next_row, next_col);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    while (cases--) {
        int graph_row, graph_col, object_location_num;
        cin >> graph_row >> graph_col >> object_location_num;

        // 동적 할당
        int** graph = new int* [graph_row + 1];
        bool** visited = new bool* [graph_row + 1];

        for (int i = 1; i <= graph_row; ++i) {
            graph[i] = new int[graph_col + 1] {};
            visited[i] = new bool[graph_col + 1] {};
        }

        for (int i = 0; i < object_location_num; ++i) {
            int row, col;
            cin >> row >> col;
            graph[row + 1][col + 1] = 1; // 인덱스 보정
        }

        int res = 0;
        for (int i = 1; i <= graph_row; ++i) {
            for (int j = 1; j <= graph_col; ++j) {
                if (!visited[i][j] && graph[i][j] == 1) {
                    DFS(graph, graph_row, graph_col, visited, i, j);
                    ++res;
                }
            }
        }

        cout << res << '\n';

        // 메모리 해제
        for (int i = 1; i <= graph_row; ++i) {
            delete[] graph[i];
            delete[] visited[i];
        }
        delete[] graph;
        delete[] visited;
    }

    return 0;
}
