// you have given a row wise short arr find a element in it.

#include<iostream>
#include<vector>
using namespace std;

// binary search
bool binarySearch(vector<vector<int>> arr,int key){

    int row=arr.size();
    int col=arr[0].size();
    int s=0;
    int e=row*col-1;

    int mid=s+(e-s)/2;
    while (s<=e)
    {
        int element=arr[mid/col][mid%col];
        if(element==key){
            return true;
        }

        else if(element< key){
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return false;
}


int main(){
    vector<vector<int>> arr;

    int row, col;
    cout << "Enter the row:";
    cin >> row;

    cout << "Enter the col:";
    cin >> col;

    cout << "Enter the input:" << endl;
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        arr.push_back(temp);
    };

    int key;
    cout<<"Element to be search:";
    cin>>key;
    bool ans=binarySearch(arr,key);
    if(ans){
        cout<<"Element is found.";
    }else{
        cout<<"Element is not found.";
    }

}