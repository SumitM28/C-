// 
#include<iostream>
using namespace std;


int duplicate(int arr[],int n){

    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans=ans^arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
    
}

int main(){

    

    int s=5;
    int arr[]={1,2,3,4,4};

    int ans=duplicate(arr,s);
    cout<<ans;

}