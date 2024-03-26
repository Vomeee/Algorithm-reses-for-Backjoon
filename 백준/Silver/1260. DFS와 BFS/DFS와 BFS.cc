#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[100001];
queue<int> Q;

void BFS(bool* visited, int size, int start_point)
{
    Q.push(start_point);
    visited[start_point] = true; // 방문 처리를 올바르게 수정

    while (!Q.empty())
    {
        int current_point = Q.front();
        cout << Q.front() << " ";
        Q.pop();

        for (int next_point : graph[current_point])
        {
            if (!visited[next_point])
            {
                visited[next_point] = true; // 방문 처리
                Q.push(next_point);
            }
        }
    }
}

void DFS(bool* visited, int size_visited, int current_point)
{
    cout << current_point << " ";
    visited[current_point] = true;

    for (int next_point : graph[current_point])
    {
        if (!visited[next_point])
        {
            DFS(visited, size_visited, next_point);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nod, side, start_nod;
    cin >> nod >> side >> start_nod;

    bool* visited = new bool[nod + 1];
    fill_n(visited, nod + 1, false); // 초기화

    for (int i = 0; i < side; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // 인접 리스트 정렬
    for (int i = 1; i <= nod; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(visited, nod, start_nod);
    cout << "\n";

    fill_n(visited, nod + 1, false); // BFS 호출 전 visited 배열 재설정
    BFS(visited, nod, start_nod);
    cout << "\n";

    // 메모리 해제
    delete[] visited;

    return 0;
}
