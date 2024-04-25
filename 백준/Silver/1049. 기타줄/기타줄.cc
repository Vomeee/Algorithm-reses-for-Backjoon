#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cut_line; // <= 100
	int num_of_brand; // <= 50

	cin >> cut_line >> num_of_brand; //input of values.
	vector<int> price_6;
	vector<int> price_1;

	for (int i = 0; i < num_of_brand; i++)
	{
		int price_set; 
		int price_sole; // >= 0 <= 1000
		cin >> price_set >> price_sole;

		price_6.push_back(price_set);
		price_1.push_back(price_sole);
		
	} //price input.

	sort(price_6.begin(), price_6.end());
	sort(price_1.begin(), price_1.end());

	int min_6 = *price_6.begin();
	int min_1 = *price_1.begin(); //최솟값으로만 사용

	int num_of_6 = cut_line / 6; //set 개수
	int num_of_1 = cut_line % 6; //낱개 개수

	int sum1 = num_of_6 * min_6 + num_of_1 * min_1;
	int sum1_1 = min_6 * (num_of_6 + 1);
	int sum2 = cut_line * min_1;

	int res;

	res = min(sum1, sum1_1);
	res = min(res, sum2);

	cout << res;

	
}