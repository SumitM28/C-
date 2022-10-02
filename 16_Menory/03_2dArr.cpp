// create a dynamically 2d array.
#include<iostream>
using namespace std;


int main(){
    int n,m;
    cout<<"Enter the row:";
    cin>>n;
    cout<<"Enter the col:";
    cin>>m;

    // n is the no of row.
    int **arr= new int*[n];
    for(int i=0;i<n;i++){
        // m is the no of columns.
        arr[i]=new int[m];
    }


    // takin input.
    for (int i = 0; i < n; i++)
    {
       for(int j=0;j<m;j++){

        cin>>arr[i][j];
       }
    }
    
    // taking output
     for (int i = 0; i < n; i++)
    {
       for(int j=0;j<m;j++){

        cout<<arr[i][j]<<" ";
       }cout<<endl;
    }


    // deletion of 2d array
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    
}