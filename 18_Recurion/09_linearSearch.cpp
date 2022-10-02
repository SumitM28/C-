// find the element by using linear Search
#include<iostream>
using namespace std;


// recursive
int linearSearch(int *arr,int s,int n,int x){
    if(s==n){
        return -1;
    }
    if(arr[s]==x){
        return s;
    }
    return linearSearch(arr,s+1,n,x);
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
    cout<<linearSearch(arr,0,n,x);
  
}