#include <iostream>
#include <queue>
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
                i = rightrootIdx;
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

void heapify(int arr[], int n, int i)
{
    int largetst = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largetst] < arr[left])
    {
        largetst = left;
    }
    if (right <= n && arr[largetst] < arr[right])
    {
        largetst = right;
    }

    if (largetst != i)
    {
        swap(arr[largetst], arr[i]);
        heapify(arr, n, largetst);
    }
}
void heapSort(int *arr, int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
int main()
{

    heap h;

    // h.insertion(1);
    // h.insertion(10);
    // h.insertion(4);
    // h.insertion(2);
    // h.insertion(20);
    // h.print();
    // h.deleteFromHeap();
    // h.print();

    int n = 6;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array now:" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);
    cout << "Printing the Sorted array:" << endl;
    for (int i = 2; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heap usign STL

    // max heap
    priority_queue<int> maxheap;
    maxheap.push(4);
    maxheap.push(2);
    maxheap.push(5);
    maxheap.push(3);

    cout << "top of max heap: ";
    cout << maxheap.top() << endl;

    maxheap.pop();
    cout << "top of max heap: ";
    cout << maxheap.top() << endl;

    if (maxheap.empty())
    {
        cout << "maxHeap is empty" << endl;
    }
    else
    {
        cout << "maxHeap is not empty" << endl;
    }

    // min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "top of min heap: ";
    cout << minheap.top() << endl;

    minheap.pop();
    cout << "top of min heap: ";
    cout << minheap.top() << endl;

    if (minheap.empty())
    {
        cout << "minheap is empty" << endl;
    }
    else
    {
        cout << "minheap is not empty" << endl;
    }

}