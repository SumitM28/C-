// create a program to revserse the array .

#include<iostream>
using namespace std;

// function to reverse the array
void reverse( int arr[],int n){

    int i=0,j=n-1;

    while (i<=j)
    {
          int temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
          i++,j--;

    }
   
}

int main(){

    int n;
    cout<<"Enter the size: ";
    cin>>n;

    int arr[n];
    for ( int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Before the reverse:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

   
    reverse(arr,n);
    cout<<"After the reverse:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}