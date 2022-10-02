// program of bubble sort.

#include <iostream>
using namespace std;


// fucntion to bubble sort.
void bubbleSort(int arr[],int n){

    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
}
int main()
{

    int arr[8] = {5, 2, 4, 3, 7, 9, 1, 6};
    int n = 8;

    cout << "Before Sorting." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);
    cout << endl;
    cout << "After Sorting." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}