#include <iostream>
#include <math.h>
using namespace std;

class MinHeap
{
public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int getMin()
    {
        return harr[0];
    }

    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            cout << "\nOverflow: Could not insert Key\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, -10000);
        extractMin();
    }
    void linearSearch(int val)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == val)
            {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value NOT Found!";
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return 10000;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << endl;
    }
    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }
};