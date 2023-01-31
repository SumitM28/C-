// topological sort
#include <bits/stdc++.h> 
using namespace std;
void topologicalSortUtil(int node, vector<bool> &visited,stack<int> &st,unordered_map<int, list<int>> &adj ){
    visited[node]=true;

    for(auto neightbour:adj[node]){
        if(!visited[neightbour]){
            topologicalSortUtil(neightbour,visited,st,adj);
        }
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int, list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    // create a visited DS
    vector<bool> visited(v);
    // create a stack
    stack<int> st;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            topologicalSortUtil(i,visited,st,adj);
        }
    }

    vector<int> ans;

    while(st.size()>0){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> topologicalSortUsingKahnAlog(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int, list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    // push all 0 indegree node in queue
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    // do bsf
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){

}