// coun all the possible inversion in the unsorted array.

#include <iostream>
using namespace std;

int mergeAndCount(int *arr, int s, int mid, int e)
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
    int swap = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            swap += (mid + 1) - (s + i);
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
    return swap;
}

int mergeSortAndCount(int *arr, int s, int e)
{
    int count = 0;
    if (s <e)
    {
        int mid = (s + e) / 2;
        count += mergeSortAndCount(arr, s, mid);
        count += mergeSortAndCount(arr, mid + 1, e);
        count += mergeAndCount(arr, s, mid, e);
    }

    return count;
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

    cout << "The inversion pair are:" << mergeSortAndCount(arr, 0, n - 1);

    delete[] arr;
}