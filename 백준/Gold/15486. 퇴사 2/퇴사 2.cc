#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int days;
	cin >> days;

	vector<int> times;
	vector<int> moneys;
	int* max_money = new int[days + 1] {}; //0으로 초기화.
	times.push_back(0);
	moneys.push_back(0); //index 0을 안쓸거임

	for (int i = 1; i <= days; i++)
	{
		int newtime;
		int newmoney;

		cin >> newtime >> newmoney;
		times.push_back(newtime);
		moneys.push_back(newmoney);
	}

	for (int i = 1; i <= days; i++)
	{
		if (times[i] == 1)
		{
			max_money[i] = max(max_money[i], max_money[i - 1] + moneys[i]);
		} // 첫날에도 index 0 이 0으로 초기화되어있으니..
		if (times[i] > 1)
		{
			if(i + times[i] - 1 <= days)
				max_money[i + times[i] - 1] = max(max_money[i - 1] + moneys[i], max_money[i + times[i] - 1]);
			max_money[i] = max(max_money[i], max_money[i - 1]);
		}
	}

	cout << max_money[days];

	  
}