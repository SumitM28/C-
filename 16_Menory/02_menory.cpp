// dynamic memory allocation.

#include<iostream>
using namespace std;


// sum of n numbers
int getSum(int *arr,int n){
    int sum=0;
    for (int  i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main(){

    // static allocation
    // char ch='s';
    // char *c=&ch;
    // cout<<sizeof(c)<<endl;

    // dynamic allocation
    int size;
    cout<<"Enter the size:";
    cin>>size;

    int *arr= new int[size];
    
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"The sum is "<<getSum(arr,size)<<" ";
    
}