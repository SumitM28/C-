// find the sum of the given array by using the recursion.
// check the given array is sorted or not
#include<iostream>
using namespace std;


// recursive
int findSum(int *arr,int n){

    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
   
    return arr[0]+findSum(arr+1,n-1);
    
}

int main(){

    int n;
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter the Input:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<findSum(arr,n);
    // cout<<*(arr+1);
}