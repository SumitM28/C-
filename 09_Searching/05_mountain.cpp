// find the peek of the mountain

#include<iostream>
using namespace std;

int binarySerach(int arr[],int n){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    while (s<e)
    {

        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return mid;


}

int main(){

    int size=10;
    int arr[size]={24,69,100,99,79,78,67,36,26,19};

    int ans=binarySerach(arr,size);

    cout<<ans;
}