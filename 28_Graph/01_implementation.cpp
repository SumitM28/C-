#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    // create edges
    addEdge(int u, int v, bool direction)
    {
        // if directiin -> 0 , undirectional
        // if directiin -> 1 , directional

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // print edge
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ,";
            }
            cout << endl;
        }
    }
};

int main()
{

    // nodes
    int n;
    cout << "Enter the no of nodes:" << endl;
    cin >> n;
    int m;
    cout << "Enter the no of edges:" << endl;
    cin >> m;

    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }

    g.printAdjList();
}