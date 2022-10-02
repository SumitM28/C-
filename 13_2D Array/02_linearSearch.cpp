// program to find a target by using linear search.

#include<iostream>
using namespace std;


// linear search 
bool isPresent(int arr[][3],int target ,int row,int col){

    for (int i = 0; i < row; i++)
    {
        for(int j=0;j<col;j++){

            if(arr[i][j]==target){
                return true;
            }
        }
        
    }
    return false;
    
}

int main(){

     int arr[3][3];
    cout<<"Insert the element insise the array:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Your target ";
    int target;
    cin>>target;
    if(isPresent(arr,target,3,3)){
        cout<<"Found";
    }else{
        cout<<"Not found";
    }
}