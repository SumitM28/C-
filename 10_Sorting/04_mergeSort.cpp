// merge sort
#include <iostream>
using namespace std;

void merge(int *arr, int s, int mid, int e)
{

    // subarray lengths
    int n1 = mid - s + 1;
    int n2 = e - mid;

    // subarrays
    int *L = new int[n1];
    int *R = new int[n2];

    // copy the element
    int k = s;
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[k++];
    }

    int i = 0, j = 0;
    k = s;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
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

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
}