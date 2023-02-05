// find articulation point in a graph.
/*
A articulation point is the node. when we remove it then the graph is divide into 2 or more sub components.
*/

#include <bits/stdc++.h>
using namespace std;

// dfs function
void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child=0;
    for(auto nbr:adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,disc, low, vis, adj, ap, timer);
            low[node]= min(low[node], low[nbr]);

            // check articulation point or not.
            if(low[nbr] >= disc[node] && parent !=-1){

                ap[node]=true;
            }
                child++;
        }else{
            low[node]=min(low[node],disc[nbr]);
        }
    }
    if(parent==-1 && child >1){
        ap[node]=true;
    }
}

int main()
{

    // no of nodes
    int n = 5;
    // no of edges
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // create adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);
    int parent = -1;

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        vis[i] = false;
    }

    // DFS
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, disc, low, vis, adj, ap, timer);
        }
    }

    cout<<"Articulation point as follow: "<<endl;
    for(int i=0;i<n;i++){
        if(ap[i]!=false){
            cout<<i<<" "; 
        }
    }
}