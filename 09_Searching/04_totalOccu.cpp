// find the total no of occurance of a number in a sorted array only.
// brute force linear search

// optimize by using binary.

#include<iostream>
using namespace std;

// binary search for find the left most index of the key.
int firstOccu(int arr[], int size,int key){

    int s=0;
    int e=size-1;
    int ans=-1;
    while (s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}
// binary search for find the right most index of the key.
int lastOccu(int arr[], int size,int key){

    int s=0;
    int e=size-1;
    int ans=-1;
    while (s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}





int main(){

    int arr[7]={1,2,3,3,3,3,5};
    int key=3;
    
    int first=firstOccu(arr,7,3);
    int last=lastOccu(arr,7,3);

    int ans=(last-first)+1;
    
    cout<<"the total no of occurance of 3 :"<<ans<<endl;

}
