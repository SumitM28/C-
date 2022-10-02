// program to reverse an array.

#include<iostream>
using namespace std;

void reverse(int arr[],int i,int j){
    if(i>=j){
        return;
    }

    swap(arr[i],arr[j]);
    reverse(arr,i+1,j-1);
}

int main(){
    int arr[6]={1,2,3,4,5,6};

  
    reverse(arr,0,5);

    for(auto i:arr){
        cout<<i<<" ";
    }
  
}