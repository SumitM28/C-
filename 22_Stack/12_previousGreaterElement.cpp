#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// brute force
vector<int> findPrevGreaterElement(int arr[],int size){

    vector<int>ans;

    for(int i=0;i<size;i++){
        int temp=-1;
        for(int j=i-0; j>=0;j--){
            if(arr[j]>arr[i]){
                
                temp=max(temp,arr[j]);
                
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

// optimize solution
vector<int> PGE(int arr[],int n){
    
    vector<int>ans(n);
    stack<int>st;
    st.push(-1);

    for(int i=0;i<n;i++){

        int curr=arr[i];
        while (st.top()!=-1 && st.top()<curr)
        {
           st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    
    return ans;
}

int main(){


    int arr[]={3,4,1,2};
    int s=4;

    vector<int>ans=PGE(arr,s);

    for(auto i:ans){
        cout<<i<<" ";
    }

}