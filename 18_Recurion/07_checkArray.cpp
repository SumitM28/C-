// check the given array is sorted or not
#include<iostream>
using namespace std;

// iterative way
// bool checkArray(int *arr,int n){

//     for(int i=0;i<n-1;i++){
//         if(arr[i]>arr[i+1]){
//             return false;
//         }
//     }
//     return true;
// }

// recursive
bool checkArray(int *arr,int n){
    // when array contain only a single element.
    //base case
    if(n==1){
        return true;
    }

    if(arr[0]<arr[1]){
        return checkArray(arr+1,n-1);
    }else{
        return false;
    }
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
    cout<<checkArray(arr,n);
}