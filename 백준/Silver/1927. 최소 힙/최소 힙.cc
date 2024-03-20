#include <iostream>

using namespace std;

void heapAdd(int* heap, int value, int& index) 
{
    index++;
    heap[index] = value;

    int current = index;
    while (current > 1) 
    {
        int parent = current / 2;
        if (heap[current] < heap[parent]) 
        {
            swap(heap[current], heap[parent]);
            current = parent; //index 업데이트
        }
        else 
        {
            break; //root를 추가하는경우
        }
    }
}

int heapDelete(int* heap, int& index) 
{
    if (index == 0)
    {
        return 0; 
    }


    int root = heap[1];
    heap[1] = heap[index];
    index--;

    int current = 1;
    while (true) 
    {
        int left = current * 2;
        int right = current * 2 + 1;
        int smallest = current;

        if (left <= index && heap[left] < heap[smallest]) 
        {
            smallest = left;
        }

        if (right <= index && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != current) 
        {
            swap(heap[current], heap[smallest]);
            current = smallest;
        }
        else 
        {
            break;
        }
    }
    return root;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	int* min_heap = new int[n];
	int max_index = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			cout << heapDelete(min_heap,max_index) << "\n";
            if (max_index > 0);
		}
		else
		{
			heapAdd(min_heap, temp, max_index);
		}
	}
}