// sort the array using quick sort
#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{

    int pivot = arr[s];
    // count all the small elements than the pivot
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    // place pivot to the right position
    int pivotIdx = s + cnt;
    swap(arr[s], arr[pivotIdx]);

    int i = s, j = e;
    while (i < pivotIdx && j > pivotIdx)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIdx && j > pivotIdx)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIdx;
}

void quickSort(int *arr, int s, int e)
{

    // base case
    if (s >= e)
        return;

    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter the input of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
}