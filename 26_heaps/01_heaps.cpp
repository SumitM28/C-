#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // insert data in heap
    void insertion(int val)
    {   
        
        size = size + 1;
        int index = size;
        arr[index] = val;

        // propogate the index value at the correct position
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // delete data from heap
    void deleteFromHeap()
    {

        // if no data is present
        if (size == 0)
        {
            return;
        }

        // replace the last element with root node
        arr[1] = arr[size];

        // remove the last node
        size--;

        // propogate the root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftrootIdx = 2 * i;
            int rightrootIdx = 2 * i + 1;

            if (leftrootIdx < size && arr[i] < arr[leftrootIdx])
            {
                swap(arr[leftrootIdx], arr[i]);
                i = leftrootIdx;
            }
            else if (rightrootIdx < size && arr[i] < arr[rightrootIdx])
            {
                swap(arr[rightrootIdx], arr[i]);
                i=rightrootIdx;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    heap h;

    h.insertion(1);
    h.insertion(10);
    h.insertion(4);
    h.insertion(2);
    h.insertion(20);
    h.print();
    h.deleteFromHeap();
    h.print();
}