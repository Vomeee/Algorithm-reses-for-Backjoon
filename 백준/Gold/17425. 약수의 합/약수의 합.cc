#include <iostream>
#include <vector>

using namespace std;

int F[1000001]{};
long long G[1000001]{};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> cases;
    cases.reserve(n); // 크기를 미리 예약

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cases.push_back(temp);
    }

    G[1] = 1;
    
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = 1; i * j <= 1000000; j++)
        {
            F[i * j] += i; 
        }

        G[i] = G[i - 1] + F[i];
    }








    for (int i : cases)
    {
        cout << G[i] << '\n';
    }
}