#include <iostream>
#include <queue>

using namespace std;

bool visited[100001]{ false, };
int time_used[100001]{};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a_initial, b_initial; //a의 위치, b의 위치
    cin >> a_initial >> b_initial;



    int current_time = 0;

    queue<int> q;
    q.push(a_initial);
    visited[a_initial] = true;
    time_used[a_initial] = 0;

    if (a_initial == b_initial) 
    {    
        cout << 0; 
        return 0;
    }

    while (!q.empty())
    {
        int a_current = q.front();
        q.pop();
        int next_coordinate[3]{a_current * 2 , a_current - 1, a_current + 1}; //다음 이동하는 위치
        for (int i : next_coordinate)
        {
            if (i >= 0 && i <= 100000 && visited[i] == false) //유효한 값에 대하여
            {
                visited[i] = true;
                q.push(i); //queue에 추가.
                time_used[i] = time_used[a_current] + 1;
                if (i == b_initial)
                {
                    cout << time_used[i];
                    return 0;
                }
            }
        }

    }

    

    return 0;
}
