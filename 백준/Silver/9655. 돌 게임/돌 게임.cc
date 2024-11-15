#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<bool> DP_SK(n + 1);
	vector<bool> DP_CY(n + 1);
	
	{
		DP_SK[0] = false;
		DP_SK[1] = true;
		DP_SK[2] = false;
		DP_SK[3] = true;
		//SK init.
		DP_CY[0] = false;
		DP_CY[1] = true;
		DP_CY[2] = false;
		DP_CY[3] = true;
		//CY init.
	}

	for (int i = 4; i <= n; i++)
	{
		DP_SK[i] = (!DP_CY[i - 1] && !DP_CY[i - 3]) ? true : false;
		DP_CY[i] = (!DP_SK[i - 1] && !DP_SK[i - 3]) ? true : false;
	}

	if (DP_SK[n])
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
}