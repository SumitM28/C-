// binary search using recursion
#include<iostream>
using namespace std;


// binary Search
int binarySearch(int *arr,int s,int e,int x){

    if(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            return mid;
        }else if (arr[mid]<x)
        {
            return binarySearch(arr,mid+1,e,x);
        }else{
            return binarySearch(arr,s,mid-1,x);
        }
        
    }
    return -1;
}


int main(){

    int n,x;
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter the Input:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be find:";
    cin>>x;
    cout<<binarySearch(arr,0,n,x);
}