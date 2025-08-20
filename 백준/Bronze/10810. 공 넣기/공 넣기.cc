#include <iostream>
using namespace std;

void ChangeArr(int startIndex, int endIndex, int* array, int var)
{
    for (int idx = startIndex - 1; idx <= endIndex - 1; idx++)
    {
        array[idx] = var; // 원본 배열에 직접 반영됨
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int* arr = new int[n]; // 동적 배열

    // 초기화
    for (int i = 0; i < n; i++) arr[i] = 0;

    for (int c = 0; c < m; c++) // testcase
    {
        int i, j, k;
        cin >> i >> j >> k;
        ChangeArr(i, j, arr, k); // ✅ 그냥 arr 넘기면 됨
    }

    // 결과 출력 (예시)
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr; // 메모리 해제
}
