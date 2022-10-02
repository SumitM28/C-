// find the row wise sum of the 2d array.
#include<iostream>
using namespace std;

// function for row wise sum
int rowSum(int arr[],int m){
    int sum=0;
    for (int i = 0; i < m; i++)
    {
        sum+=arr[i];
    }
    
    return sum;
}

int main(){
    int row,col;
    cout<<"enter the size of rows :";
    cin>>row;
    cout<<"enter the size of rows :";
    cin>>col;

     int arr[row][col];
    cout<<"Insert the element insise the array:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    

    for (int i = 0; i < row; i++)
    {
        cout<<"The sum of row "<<i+1<<" "<<rowSum(arr[i],col)<<endl;
       
    }
    

}