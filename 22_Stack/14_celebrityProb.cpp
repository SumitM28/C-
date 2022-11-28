#include<iostream>
#include<vector>
#include<stack>
using namespace std;


bool checkCelebrity(vector<vector<int>>arr,int n,int i){

    
    //check inside row
    for(int j=0;j<n;j++){

        if(i==j){
            continue;
        }

        if(arr[i][j]==1){
            return false;
        }
    }

    // check inside column
    for(int j=0;j<n;j++){

        if(i==j){
            continue;
        }

        if(arr[j][i]==0){
            return false;
        }

    }

    return true;
}

// brute force solution 
int FindCelebrity(vector<vector<int>>arr,int n){

    for(int i=0;i<n;i++){

        if(checkCelebrity(arr,n,i)){
            return i;
        }
    }
}


// optime 1
bool knows(vector<vector<int>>arr,int a,int b,int n){

    if(arr[a][b]==1){
        return true;
    }else{
        return false;
    }
}


int FindCelebrityOptimize(vector<vector<int>>arr,int n){

    // push all the member
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }

    // pop untill size of stack is not 1
    while (s.size()!=1)
    {
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();

        if(knows(arr,a,b,n)){
            s.push(b);
        }else{
            s.push(a);
        }
    
    }

    int ans=s.top();

    // check in row 
    for(int i=0;i<n;i++){
        
        if(arr[ans][i]==1){
            return -1;
        }
    }

    // check in column
    for(int i=0;i<n;i++){

        if(ans==i){
            continue;
            if(arr[i][ans]==0){
                return -1;
            }
        }
    }

    return ans;
}




int main(){

    cout<<"Enter the size of arr: ";
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));   
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int celeb=FindCelebrityOptimize(arr,n);
    cout<<celeb;
     
}