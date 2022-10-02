// program to rotate a array by k time
#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& arr,int k){
    vector<int>temp(arr.size());

    for(int i=0;i<arr.size();i++){
        temp[(i+k)%arr.size()]=arr[i];
    }

    arr=temp;
}

int main(){

    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    cout<<"Before Rotate"<<endl;
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
  
    rotate(arr,2);
    cout<<"After Rotate"<<endl;
    for(auto i:arr){
        cout<<i<<" ";
    }
}