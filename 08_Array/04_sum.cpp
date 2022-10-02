// create a program to find the sum of the array

#include<iostream>
using namespace std;

int main(){

    int size;
    cout<<"Enter the size: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the input: "<<"\n";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }

    cout<<"The sum of all the element present in the array: "<<sum<<endl;
    return 0;
}