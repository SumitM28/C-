// create a program of linear search.

#include<iostream>
using namespace std;

// time complexity O(n)
// linear search function
int linearSearch(int arr[],int n,int num){

    for(int i=0;i<n;i++){

        if(arr[i]==num){
            return i;
        }
    }
    return 0;
}

int main(){
    

    int size;
    cout<<"Enter the size: ";
    cin>>size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    int num;
    cout<<"Enter the number to be find: ";
    cin>>num;


    int ans=linearSearch(arr,size,num);

    if(ans==0){
        cout<<"Element not found.";
    }else{
        cout<<"Element is found at index "<<ans;
    }

    return 0;
}