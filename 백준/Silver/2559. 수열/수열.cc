#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num_count, add_count;
    cin >> num_count >> add_count;

    int* digits = new int[num_count];

    for (int i = 0; i < num_count; i++)
    {
        cin >> digits[i];
    }

    int* sums = new int[num_count - add_count];

    int res = 0;
    for (int i = 0; i < add_count; i++)//addcount 5 라면 index 4까지.
    {
        res += digits[i];
    }//res = addcount 만큼의 개수 더한 수.
    int temp = res;

    for (int i = add_count; i < num_count; i++)
    { // ac == 2라면 3 더하고 1빼야됨(index)
        temp = temp + digits[i] - digits[i - add_count];
        if (temp > res)
        {
            res = temp;
        }
    }

    cout << res;


}
