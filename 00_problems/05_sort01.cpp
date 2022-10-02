#include<iostream>
using namespace std;

void sort01(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){

        if(arr[i]==0){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
    }
}

int main(){


    int n=6;
    int arr[]={ 0, 1,1 ,0,0 ,1};

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    sort01(arr,n);
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}