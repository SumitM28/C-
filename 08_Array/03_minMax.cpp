// write a program to find the min and max in hte given array.

#include<iostream>
using namespace std;

int main(){
    

    int size;
    cout<<"Enter the size: ";
    cin>>size;
    int arr[size];

    int  max,min;
    cout<<"Enter the input:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;

    max=arr[0];
    min=arr[0];
    for (int i = 1; i < size; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    
    cout<<"The min max is: "<<min<<" "<<max<<endl;
    
    

    return 0;
}