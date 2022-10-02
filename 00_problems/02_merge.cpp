// merge 2 sorted arr.

#include<iostream>
#include<vector>
using namespace std;

int merge(int arr1[],int arr2[],int n,int m){
    int ans[n+m];

    int i=0;
    int j=0;
    int k=0;
    while (i<n && j<m)
    {
       if(arr1[i]<=arr2[j]){
        ans[k++]=arr1[i++];
       }else{
        ans[k++]=arr2[j++];
       }
    }

    while (i<n)
    {
        ans[k++]=arr1[i++];
    }
    while (j<m)
    {
        ans[k++]=arr2[j++];
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
    
}


int main(){



    int arr1[4]={1,2,7,9};
    int arr2[3]={3,5,6};

    int ans1=merge(arr1,arr2,4,3);
  

}