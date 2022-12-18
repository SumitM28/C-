#include<bits/stdc++.h>
using namespace std;


// time complexity O(n) space O(1)
vector<long long>firstNegativeInteger(long long int A[],
                                             long long int N, long long int k){
    vector<long long> ans;
    for(int i=0;i<N-k+1;i++){
        int firstNegative=0;
        for(int j=i;j<k+i;j++){
            if(A[j]<0){
                firstNegative=A[j];
                break;
            }
        }
        ans.push_back(firstNegative);
    }
    return ans;
}



// time complexty O(n) and space O(n)
vector<long long>FirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    
    deque<long long int>dq;
    vector<long long>ans;
    
    // process 1st window
    for(int i=0;i<k;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
              
    // store ans for 1st window
    if(dq.size()>0){
        
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }
    
    
    // process remaining window
    for(int i=k;i<N;i++){
        
        // remove the element if size of window is greater than k
        if( !dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        
        // store the new element
        if(A[i]<0){
            dq.push_back(i);
        }
        if(dq.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(A[dq.front()]);
        }
        
        
    }
    return ans;
 }

int main(){
    long long int A[]={-8, 2, 3, -6, 10};
    long long int N=5;
    long long int k=2;
    vector<long long> ans=firstNegativeInteger(A,N,k);
    for( auto i:ans){
        cout<<i<<" ";
    }
}