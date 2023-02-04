// find shortest path usign Dijkstra's Shortest path.

#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create adajency list
    unordered_map< int, set< pair<int,int> > > adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].insert(make_pair(v,w));
        adj[v].insert(make_pair(u,w));
    }

    // create a distance data structure.
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }

    // create a set
    set<pair<int,int> > st;
    dist[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){

        // fetch top of set.
        auto top = *(st.begin());

        int nodeDist= top.first;
        int node=top.second;

        // remove from set
        st.erase(st.begin());

        // traverse on neighbour
        for(auto neighbour : adj[node]){
            if(nodeDist + neighbour.second < dist[neighbour.first]){


                // find record if exist
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record != st.end()){
                    st.erase(record);
                }

                // update the distance
                dist[neighbour.first]= nodeDist+ neighbour.second;

                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}

int main(){
    
}