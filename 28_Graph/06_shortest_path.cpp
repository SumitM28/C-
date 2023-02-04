// find shorted path in a directed graph.
#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    // create a adjajency list.
    unordered_map<int, set<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);

        adj[u].insert(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " ";

            for (auto j : i.second)
            {
                cout << "[ " << j.first << "," << j.second << " ]";
            }
            cout << endl;
        }
    }
};
void dfs(int node, unordered_map<int, set<pair<int, int>>> &adj, unordered_map<int, bool> &visited, stack<int> &s)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour.first])
        {
            dfs(neighbour.first,adj,visited,s);
        }
    }
    s.push(node);
}

int main()
{
    graph *g = new graph();
    g->addEdge(0, 1, 5);
    g->addEdge(0, 2, 3);
    g->addEdge(1, 2, 2);
    g->addEdge(1, 3, 6);
    g->addEdge(2, 3, 7);
    g->addEdge(2, 4, 4);
    g->addEdge(2, 5, 2);
    g->addEdge(3, 4, -1);
    g->addEdge(4, 5, -2);

    g->printAdj();

    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {
            dfs(i, g->adj, visited, s);
        }
    }

    while (!s.empty())
    {
        int top=s.top();
        s.pop();
        cout<<top<<" ";

    }
    
    int src=1;
    vector<int> dist;

    for(int i=0;i<n;i++){
        adj[i]=INT16_MAX;
    }
}