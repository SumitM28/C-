#include<iostream>
using namespace std;

// for taking the input.
void inputArrar(int arr[],int size){

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}


// for printing the array.
void printArray(int arr[],int size){

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){

    int arr[10];

    cout<<"Enter the input:"<<endl;

    inputArrar(arr,10);

    cout<<"Print the array."<<endl;
    printArray(arr,10);

    return 0;
}