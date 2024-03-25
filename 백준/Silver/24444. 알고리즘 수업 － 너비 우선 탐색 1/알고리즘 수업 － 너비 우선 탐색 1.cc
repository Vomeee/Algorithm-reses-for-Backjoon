#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[100001]; //인접 정점 표시 vector. 걍 global variable 화. 나중에 class 묶는 연습.
queue<int> Q;





int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nod, side, start_point;
    cin >> nod >> side >> start_point;
    
    bool* visited = new bool[nod + 1] {false, };
    visited[start_point] = true;

    for (int i = 0; i < side; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    int current_point = start_point;

    // 인접 리스트 정렬
    for (int i = 1; i <= nod; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    int* res = new int[nod + 1] {};
    int count = 1;
    // BFS 시작
    Q.push(start_point);

    while (!Q.empty()) {
        current_point = Q.front();
        Q.pop();
        res[current_point] = count; // 현재 정점 출력
        count++;

        for (int next_point : graph[current_point]) {
            if (!visited[next_point]) {
                visited[next_point] = true; // 방문 처리
                Q.push(next_point);
            }
        }
    }

    for (int i = 1; i <= nod; i++)
    {
        cout << res[i] << '\n';
    }

    // 메모리 해제
    delete[] visited;

   
    
}
