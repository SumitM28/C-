#include<iostream>
#include<vector>
#include<string>
using namespace std;

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
    int x=0,y=0;
    string out="";
    vector<string>ans;
    solve(m,x,y,visited,out,ans);
    for (int i = 0; i < ans.size(); i++)
    {
       cout<<ans[i];
    }
    

}