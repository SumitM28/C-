// find the largest sum row.

#include<iostream>
using namespace std;

int getMaxSumRow(int arr[][3],int n,int m){
    int max=0;
    int rowIndex;
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=arr[i][j];
        }

        if(sum>max){
            max=sum;
            rowIndex=i;
        }
    }
    cout<<"Maximum Sum is "<<max<<endl;
    return rowIndex;
}
int main(){
    int row,col;
    cout<<"enter the size of rows :";
    cin>>row;
    cout<<"enter the size of rows :";
    cin>>col;

     int arr[3][3];
    cout<<"Insert the element insise the array:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

   
    int ans=getMaxSumRow(arr,row,col);
    cout<<ans;
}