#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr_size, number_of_calc;
    cin >> arr_size >> number_of_calc; //initial input.

    int** list = new int* [arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        list[i] = new int[arr_size] {};
    } 
    
    int** calc_list = new int* [number_of_calc];
    for (int i = 0; i < number_of_calc; i++)
    {
        calc_list[i] = new int[4];
    }//dynamic allocation. 

    //input.
    for (int i = 0; i < arr_size; i++)
    {
        int temp = 0;
        cin >> list[i][0];
        
        for (int j = 1; j < arr_size; j++)
        {
            cin >> temp;
            list[i][j] = list[i][j - 1] + temp;
        }
    }

    for(int i = 0; i < number_of_calc; i++)
        for (int j = 0; j < 4; j++)
        {
            cin >> calc_list[i][j];
        }
    //end of input.

    for (int i = 0; i < number_of_calc; i++)
    {
        int x1 = calc_list[i][0] - 1;
        int y1 = calc_list[i][1] - 1;
        int x2 = calc_list[i][2] - 1;
        int y2 = calc_list[i][3] - 1;

        long long res = 0;

        for (int j = x1; j <= x2; j++)
        {
            if (y1 != 0)
            {
                res += (list[j][y2] - list[j][y1 - 1]);
            }
            else
            {
                res += list[j][y2];
            }
        }

        cout << res << "\n";
    }

}
