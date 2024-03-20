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
        if (heap[current] > heap[parent]) 
        {
            swap(heap[current], heap[parent]);
            current = parent;
        }
        else 
        {
            break;
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
        int largest = current;

        if (left <= index && heap[left] > heap[largest]) 
        {
            largest = left;
        }

        if (right <= index && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != current) 
        {
            swap(heap[current], heap[largest]);
            current = largest;
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

	int* max_heap = new int[n];
	int max_index = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			cout << heapDelete(max_heap,max_index) << "\n";
            if (max_index > 0);
		}
		else
		{
			heapAdd(max_heap, temp, max_index);
		}
	}
}