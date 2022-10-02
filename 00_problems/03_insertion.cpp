// find the insertion of 2 arrays

// create a program to swap alternative values in the array.

#include<iostream>
#include <vector>
using namespace std;

vector<int> insertion(int arr1[],int arr2[],int n,int m){
    vector<int>ans;

    for(int i=0;i<n;i++){

        int temp=arr1[i];

        for (int j = 0; j < m; j++)
        {
            if(temp<arr2[j]){
                break;
            }

            if(temp==arr2[j]){
                ans.push_back(temp);
                arr2[j]=-1;
                break;
            }
        }
        
    }
    return ans;

}

int main(){

    int n1;
    cout<<"Enter the size of array 1:";
    cin>>n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }

    int n2;
    cout<<"Enter the size of array 2:";
    cin>>n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }
    
    vector<int> ans=insertion(arr1,arr2,n1,n2);
    for(auto elem:ans){
        cout<<elem<<" ";
    }
    
}