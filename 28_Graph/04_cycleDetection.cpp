// cycle detection in graph.
#include<bits/stdc++.h>
using namespace std;


// using DFS
bool isCyclicDFS(int src,int parent,unordered_map<int,bool> &visited,unordered_map<int,set<int>>&adj )
{
    visited[src]=true;

    for (auto neighbour: adj[src]){
        if(!visited[neighbour]){
            bool temp = isCyclicDFS(neighbour,src,visited,adj);
            if(temp){
                return true;
            }
        }else if(neighbour != parent){
            return true;
        }

    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,set<int>>adj;
    unordered_map<int,bool>visited;
    //creating adjacency List from edges vector
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    //calling bfs function to detect cylce
    
    for(int i=0;i<n;i++){
       if(!visited[i]){
            bool ispresent=isCyclicDFS(i,-1,visited,adj);
           if(ispresent)
            return "Yes";
       }
        
    }
    return "No";
}

int main(){

}