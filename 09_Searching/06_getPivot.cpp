// find the pivot element in the array.

#include<iostream>
using namespace std;

int getPivot(int arr[],int n){

    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while (s<e)
    {

        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int main(){

    int arr[5]={7,9,1,2,3};
    int n=5;
    int ans=getPivot(arr,n);
    cout<<"the pivot element is "<<arr[ans]<<endl;
}
