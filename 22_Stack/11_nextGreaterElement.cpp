#include<bits/stdc++.h>
using namespace std;


// brute force approach
vector<int> findNGE(int *arr,int s){

    vector<int>ans;
    for (int i = 0; i < s; i++)
    {
        int smaller=-1;
        for(int j=i+1;j<s;j++){

            if(arr[i]<arr[j]){
                smaller=arr[j];
                break;
            }
        }

        ans.push_back(smaller);
    }
    
    return ans;
}


// optimize solution
vector<int> NGE(int arr[],int s){

    vector<int>ans(s);
    stack<int>st;
    st.push(-1);

    for(int i=s-1;i>=0;i--){
        
        int curr=arr[i];
        
        while (st.top()!=-1 && arr[i]>st.top())
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(arr[i]);
    }

    
    
    return ans;
}

int main(){
    
    int arr[]={13 , 7, 6 , 12}; 
    int s=4;
    vector<int>ans=NGE(arr,s);
    for(auto i:ans){
        cout<<i<< " ";
    }
}