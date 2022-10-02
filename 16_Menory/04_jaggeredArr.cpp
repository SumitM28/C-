// create a jaggered array dynamically.

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the row:";
    cin>>n;
    int **arr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        cout<<"Enter the col for row "<<i<<":";
        cin>>m;
        arr[i]=new int[m];
    }
    // takig input
    for (int i = 0; i < n; i++)
    {   
        int m=sizeof(arr[i])/sizeof(arr[i][0]);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    // taking output
    for (int i = 0; i < n; i++)
    {   
        int m=sizeof(arr[i])/sizeof(arr[i][0]);
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    
    
}