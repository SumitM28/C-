// find a minimum spanning tree.
#include<bits/stdc++.h>
using namespace std;

// using prim's alogrithms.
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create ajajency list
    unordered_map<int, set<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].insert(make_pair(v, w));
        adj[v].insert(make_pair(u, w));
    }

    // create 3 data structure
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}

// using Kruskal's Shortest Path.

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

// find parent function
int findParent(vector<int> &parent, int node)
{
    // base case
    if (parent[node] == node)
    {
        return node;
    }

    // path compression process
    return parent[node] = findParent(parent, parent[node]);
}

// union set function
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);

    for(int i=0;i<n;i++){
      parent[i]=i;
      rank[i]=0;
    }
    int minWeight=0;
    for(int i=0;i<edges.size();i++){
      int u=findParent(parent,edges[i][0]);
      int v=findParent(parent,edges[i][1]);
      int w=edges[i][2];

      if(u!=v){
        minWeight+=w;
        unionSet(u,v,parent,rank);
      }
    }
    return minWeight;
}