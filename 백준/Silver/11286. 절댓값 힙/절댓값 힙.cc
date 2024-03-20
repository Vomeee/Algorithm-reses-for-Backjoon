#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int absSmallestIndex(int* list, int i1, int i2, int index) {
    // 범위를 벗어나는 인덱스를 처리합니다.
    if (i1 > index) return i2;
    if (i2 > index) return i1;

    int abs1 = abs(list[i1]);
    int abs2 = abs(list[i2]);

    if (abs1 < abs2 || (abs1 == abs2 && list[i1] < list[i2])) {
        return i1;
    }
    else {
        return i2;
    }
}

void heapAdd(int* heap, int value, int& index) {
    index++;
    heap[index] = value;

    int current = index;
    while (current > 1) {
        int parent = current / 2;
        if (abs(heap[current]) < abs(heap[parent]) || (abs(heap[current]) == abs(heap[parent]) && heap[current] < heap[parent])) {
            swap(heap[current], heap[parent]);
            current = parent;
        }
        else {
            break;
        }
    }
}

int heapDelete(int* heap, int& index) {
    if (index == 0) {
        return 0;
    }

    int root = heap[1];
    heap[1] = heap[index];
    index--;

    int current = 1;
    while (current <= index) {
        int left = 2 * current;
        int right = 2 * current + 1;
        int smallest = absSmallestIndex(heap, current, left, index);
        smallest = absSmallestIndex(heap, smallest, right, index);

        if (smallest != current) {
            swap(heap[current], heap[smallest]);
            current = smallest;
        }
        else {
            break;
        }
    }
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int* absmin_heap = new int[n + 1](); // 인덱스 1부터 시작합니다.
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if (temp == 0) {
            cout << heapDelete(absmin_heap, max_index) << "\n";
        }
        else {
            heapAdd(absmin_heap, temp, max_index);
        }
    }

    delete[] absmin_heap;
    return 0;
}
