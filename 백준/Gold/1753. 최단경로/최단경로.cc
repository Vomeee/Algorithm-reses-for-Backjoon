#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int node_num, edge_num, start_node;
    cin >> node_num >> edge_num >> start_node;
    start_node--; // 입력을 0-based indexing으로 조정

    // 인접 리스트 생성: 각 노드에서 (목적지 노드, 거리) 쌍을 저장
    vector<vector<pair<int, int>>> graph(node_num);

    for (int i = 0; i < edge_num; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // 입력을 0-based indexing으로 조정
        graph[u].push_back(make_pair(v, w)); // 노드 u에서 v로 가는 가중치 w의 간선 추가
    }

    // Dijkstra 알고리즘
    vector<int> distances(node_num, INF);
    distances[start_node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start_node)); // (거리, 노드) 쌍으로 삽입

    while (!pq.empty()) {
        int distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (distances[current_node] < distance) continue; // 이미 더 짧은 경로를 찾았다면 무시

        for (auto& edge : graph[current_node]) {
            int next_node = edge.first;
            int next_distance = distance + edge.second;

            if (next_distance < distances[next_node]) {
                distances[next_node] = next_distance;
                pq.push(make_pair(next_distance, next_node));
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < node_num; i++) {
        if (distances[i] == INF)
            cout << "INF" << '\n';
        else
            cout << distances[i] << '\n';
    }

    return 0;
}
