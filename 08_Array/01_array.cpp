// iplementation of the array.

#include<iostream>
using namespace std;

int main(){

    int arr[15];

    cout<<"Enter the numbers for array: "<<endl;
    for(int i=0;i<15;i++){
        cin>>arr[i];
    }

    cout<<"The array is:"<<endl;
    for (int i = 0; i < 15; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    char ch[5]={'a','b','c','d','e'};
    cout<<ch[3];
  return 0;  
}