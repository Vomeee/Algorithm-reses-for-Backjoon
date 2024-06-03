#include <iostream>
#include <vector>
#include <cmath> // abs 함수 사용을 위해 추가

using namespace std;

int sum = 0;
vector<int> obj_count(26);

void check(string s)
{
    vector<int> alphabet_count(26);
    for (char c : s)
    {
        alphabet_count[c - 'A']++;
    }

    int diff_count = 0;
    int diff_indexes[2] = { -1, -1 };
    int di = 0;

    for (int i = 0; i < 26; i++)
    {
        if (alphabet_count[i] != obj_count[i])
        {
            if (diff_count < 2)
            {
                diff_indexes[di++] = i;
            }
            diff_count++;
        }
    }

    if (diff_count == 0)
    {
        sum++; // 완전히 같은 경우
    }
    else if (diff_count == 1)
    {
        if (abs(alphabet_count[diff_indexes[0]] - obj_count[diff_indexes[0]]) == 1)
        {
            sum++; // 하나의 문자만 차이가 나는 경우
        }
    }
    else if (diff_count == 2)
    {
        if ((alphabet_count[diff_indexes[0]] - obj_count[diff_indexes[0]] == 1 && 
             alphabet_count[diff_indexes[1]] - obj_count[diff_indexes[1]] == -1) ||
            (alphabet_count[diff_indexes[0]] - obj_count[diff_indexes[0]] == -1 &&
             alphabet_count[diff_indexes[1]] - obj_count[diff_indexes[1]] == 1))
        {
            sum++; // 두 개의 문자가 서로 교환 가능
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string obj;
    cin >> obj;

    for (char c : obj)
    {
        obj_count[c - 'A']++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        string temp;
        cin >> temp;
        check(temp);
    }

    cout << sum;
    return 0;
}
