#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> connections(5001);
vector<bool> visited(5001, false);

long long max_dist = 0;

void DFS(int current_node, long long current_sum)
{
    //visit update.
    visited[current_node] = true;
    
    //check and execute.
    bool isTerminal = true;

    for (auto &it : connections[current_node])
    {
        if (!visited[it.first]) // it has next node.
        {
            DFS(it.first, current_sum + it.second);
            isTerminal = false;
        }
    }

    if (isTerminal) //this is terminal node. no update existed.
    {
        max_dist = max(max_dist, current_sum);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);



    int n;
    cin >> n; 

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; //c == distance bet 2 vertex.

        connections[a].push_back(make_pair(b, c));
        connections[b].push_back(make_pair(a, c)); 
    }

    //Search.
    visited[1] = false;

    DFS(1, 0); //start point = 1, start sum = 0.

    cout << max_dist;

    return 0;
}
