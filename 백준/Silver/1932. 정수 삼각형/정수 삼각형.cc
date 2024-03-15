#include <iostream>
#include <algorithm> // max_element 함수를 사용하기 위해 추가

using namespace std;

int main()
{
    int n;
    cin >> n;

    int tri[500][500]{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }

    int** DB = new int* [n]; // 수정: DB의 크기를 입력받은 n에 맞게 조정
    for (int i = 0; i < n; i++)
    {
        DB[i] = new int[n] {}; // 각 행을 n 크기로 초기화
    }

    DB[0][0] = tri[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                DB[i][j] = DB[i - 1][j] + tri[i][j];
            }
            else if (j == i)
            {
                DB[i][j] = DB[i - 1][j - 1] + tri[i][j];
            }
            else
            {
                DB[i][j] = max(DB[i - 1][j - 1] + tri[i][j], DB[i - 1][j] + tri[i][j]);
            }
        }
    }

    // 최대 합을 찾기 위해 마지막 행에서 max_element 사용
    cout << *max_element(DB[n - 1], DB[n - 1] + n) << endl;

    // 할당된 메모리 해제
    for (int i = 0; i < n; i++)
    {
        delete[] DB[i];
    }
    delete[] DB;
}
