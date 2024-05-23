#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int obj;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> obj;

    int* dp = new int[obj + 1] {};


    for (int i = 2; i <= obj; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[obj];
}