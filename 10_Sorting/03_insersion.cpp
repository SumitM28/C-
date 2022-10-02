// program to insersion sort

#include<iostream>
using namespace std;

void insersionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}

int main(){

    int arr[8] = {5, 2, 4, 3, 7, 9, 1, 6};
    int n = 8;

    cout << "Before Sorting." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    insersionSort(arr,n);

    cout << endl;
    cout << "After Sorting." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}