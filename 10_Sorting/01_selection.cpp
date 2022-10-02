// program of selection sort.

#include <iostream>
using namespace std;

// fucntion to selection sort.
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++){

            if(arr[min]>arr[j]){
                min=j;
            }
        }

        swap(arr[i],arr[min]);
    }
}

int main()
{

    int arr[8] = {5, 2, 4, 3, 7, 9, 1, 6};
    int n = 8;

    cout << "Before Sorting."<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    selectionSort(arr, n);
    cout<<endl;

    cout << "After Sorting."<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}