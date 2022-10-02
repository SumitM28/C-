// create a program to swap alternative values in the array.

#include<iostream>
using namespace std;


void swap(int arr[],int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;

}

void swapAlternative(int arr[],int n){

    int i=0,j=i+1;

    while (i<n && j<n)
    {
        swap(arr,i,j);
        i+=2;
        j+=2;
    }
    
}

int main(){

    int n;
    cout<<"Enter the size :";
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];

    }

    cout<<"before the swaping"<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;


    cout<<"After the swaping"<<endl;
    swapAlternative(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";

    }

}