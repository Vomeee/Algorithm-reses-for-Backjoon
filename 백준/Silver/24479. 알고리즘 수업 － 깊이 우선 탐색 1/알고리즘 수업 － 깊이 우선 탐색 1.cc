#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001]; //인접 정점 표시 vector. 걍 global variable 화. 나중에 class 묶는 연습.
int res[100001]{};


void dfs(bool* &visited, int current_point, int &count)
{
    res[current_point] = count;
    count++;
    visited[current_point] = true;

    for (auto it = graph[current_point].begin(); it != graph[current_point].end(); it++)
    {
        if (!visited[*it]) //true면
        {
            dfs(visited, *it, count ); //recursion.
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nod, side, start_nod;
    cin >> nod >> side >> start_nod;

    

    bool* visited = new bool[nod + 1] {false, }; //dynamic alloc. 0안씀.

    // 간선 입력 받기
    for (int i = 0; i < side; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // 모든 인접 리스트를 한 번에 정렬
    for (int i = 1; i <= nod; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    int count = 1;

    dfs(visited, start_nod, count);

    // 결과 출력
    for (int i = 1; i <= nod; i++)
    {
        cout << res[i] << '\n';
    }

    delete[] visited; // 메모리 해제


   
    
}
