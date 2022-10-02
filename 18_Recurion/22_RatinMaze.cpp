// find all the  possible path for rat in maze
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int x,int y ,int n,vector<vector<int>> visited,vector<vector<int>> arr){

    if(x>=0 && x<n && y>=0 && y<n && visited[x][y]==0 && arr[x][y]==1){
        return true;
    }else{
        return false;
    }
}


void solve(vector<vector<int>>&m,int x,int y,int n,vector<vector<int>>visited,string out,vector<string> &ans){
    if(x==n-1 && y==n-1){
        ans.push_back(out);
        return;
    }

    visited[x][y]=1;
    int newx,newy;

    // Down
    newx=x+1;
    newy=y;
    if(isSafe(newx,newy,n,visited,m)){
        out.push_back('D');
        solve(m,newx,newy,n,visited,out,ans);
        out.pop_back();
    }
    // UP
    newx=x-1;
    newy=y;
    if(isSafe(newx,newy,n,visited,m)){
        out.push_back('U');
        solve(m,newx,newy,n,visited,out,ans);
   
        out.pop_back();
    }
    // Right
    newx=x;
    newy=y+1;
    if(isSafe(newx,newy,n,visited,m)){
        out.push_back('R');
        solve(m,newx,newy,n,visited,out,ans);
        out.pop_back();
    }
    // left
    newx=x;
    newy=y-1;
    if(isSafe(newx,newy,n,visited,m)){
        out.push_back('L');
        solve(m,newx,newy,n,visited,out,ans);
        out.pop_back();
    }

    visited[x][y]=0;
}


int main(){
    int n;
    cout<<"Enter the value:";
    cin>>n;
    vector<vector<int>>m(n,vector<int>(n,0));

    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    vector<vector<int>>visited=m;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    
    int x=0,y=0;
    string out="";
    vector<string>ans;
    solve(m,x,y,n,visited,out,ans);
    for (int i = 0; i < ans.size(); i++)
    {
       cout<<ans[i]<<" ";
    }
    

}