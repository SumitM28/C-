#include<iostream>
#include<array>
using namespace std;



int main(){
    // it is a static array that means  it is fixed size.
    array<int,5>arr={1,2,3,4,5};
    
    
    int n=arr.size();

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    cout<<"at the positon 2 element "<<arr.at(1)<<" "<<endl;;
    
    cout<<"The fisrt element of the array "<<arr.front()<<endl;
    cout<<"The last element of the array "<<arr.back()<<endl;


}