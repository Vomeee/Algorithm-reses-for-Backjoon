#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[26][26]{ 0,{0,} }; //일단 격자 모두 0으로 초기화하고 크기도 최대값으로 조정.
bool visited[26][26]{ false, {false,} }; //각 노드에 해당하는 visited, false로 초기화
vector<int> v;
int total_num = 0; //단지의 개수
int temp_value = 0; //dfs 값을 임시로 저장하는 value, 일단 전역변수화

void DFS(int graph_size, int current_point_row, int current_point_col)
{    
    visited[current_point_row][current_point_col] = true;
    temp_value++;
    if (current_point_row - 1 >= 1 && a[current_point_row - 1][current_point_col] == 1 && !visited[current_point_row - 1][current_point_col])
    { //위 좌표의 집에 대해. 그 집의 value가 1이라면, 방문도 안되어있어야 함.
        DFS(graph_size, current_point_row - 1, current_point_col);
    }
    if (current_point_col - 1 >= 1 && a[current_point_row][current_point_col - 1] == 1 && !visited[current_point_row][current_point_col - 1])
    { //왼쪽 좌표의 집에 대해. 그 집의 value가 1이라면..
        DFS(graph_size, current_point_row, current_point_col - 1);
    }
    if (current_point_row + 1 <= graph_size && a[current_point_row + 1][current_point_col] == 1 && !visited[current_point_row + 1][current_point_col])
    { //아래쪽 좌표의 집에 대해. 그 집의 value가 1이라면..
        DFS(graph_size, current_point_row + 1, current_point_col);
    }
    if (current_point_col + 1 <= graph_size && a[current_point_row][current_point_col + 1] == 1 && !visited[current_point_row][current_point_col + 1])
    { //오른쪽 좌표의 집에 대해. 그 집의 value가 1이라면..
        DFS(graph_size, current_point_row, current_point_col + 1);
    }
   
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0; //지도의 side 의 크기
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = s[j - 1] - '0';
        }
    } //입력

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] == false && a[i][j] == 1)
            {
                DFS(n, i, j);
                total_num++; //탐색 한번에 1씩 올라가야 하는 값.
                v.push_back(temp_value); //vector에 저장, 나중에 정렬할 것.
                temp_value = 0; //다음 dfs의 시작을 위해
            }
        }
    }
    
    sort(v.begin(), v.end()); //vector 정렬
    cout << total_num << '\n'; //단지 갯수 출력
    
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << '\n';
    }


    return 0;
}
