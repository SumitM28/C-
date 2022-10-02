// sort the array using selection sort with recursion.
#include<iostream>
using namespace std;

void selectionSort(int *arr,int i,int n){

    // base case
    if(n==0 || n==1) return ;
    if(i==n-1) return ;
    int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[min]>arr[j]){
            min=j;
        }
    }

    swap(arr[i],arr[min]);
    selectionSort(arr,i+1,n);
}


int main(){

    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int *arr=new int[n];

    cout<<"Enter the input of array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    selectionSort(arr,0,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}