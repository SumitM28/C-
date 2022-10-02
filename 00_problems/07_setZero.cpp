// program to move all the zeros in the last.
#include<iostream>
using namespace std;

void setZero(int arr[],int n){
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if((arr[i]!=0)){
            arr[j]=arr[i];
            j++;
        }
    }
    while (j<n)
    {
        arr[j]=0;
        j++;
    }
    
    
}
int main(){

    int arr[5]={0,2,0,5,3};

    setZero(arr,5);
    for(auto i:arr){
        cout<<i<<" ";
    }
}