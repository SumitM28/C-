#include <bits/stdc++.h> 
using namespace std;
void bfs(unordered_map<int,set<int>> &adjList, unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        // store front node in ans
        ans.push_back(frontNode);
        
        // traverse all frontNode neighbours;
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool>visited;

    // create graph
    for(auto i:edges){
        adjList[i.first].insert(i.second);
        adjList[i.second].insert(i.first);
    }

    // traverse all componets of graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}

int main(){
    
}