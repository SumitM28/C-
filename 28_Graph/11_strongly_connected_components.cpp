// Count Strongly Connected Components (Kosaraju’s Algorithm)
#include<bits/stdc++.h>
using namespace std;
void revDfs(int node,unordered_map<int,bool> &vis, unordered_map<int ,set<int> > &transpose ){
	vis[node]=true;

	for(auto nbr:transpose[node]){
		if(!vis[nbr]){
			revDfs(nbr,vis,transpose);
		}
	}
}
void dfs(int node,stack<int> &st, unordered_map<int,bool> &vis,unordered_map<int, set<int>> &adj ){
	vis[node]=true;

	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			dfs(nbr,st,vis,adj);
		}
	}
	
	// topological sort
	st.push(node);
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Create adj list
	unordered_map<int, set<int>> adj;

	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];

		// directed graph
		adj[u].insert(v);
	}	

	stack<int>st;
	unordered_map<int,bool> vis(v);

	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,st,vis,adj);
		}
	}

	// create a tranpose
	unordered_map<int ,set<int> > transpose;
	for(int i=0;i<v;i++){
		vis[i]=false;
		for(auto nbr:adj[i]){
			transpose[nbr].insert(i);
		}
	}

	// dfs using topplogical order
	int count=0;
	while(!st.empty()){
		int front=st.top();
		st.pop();
		if(!vis[front]){
			count++;
			revDfs(front,vis,transpose);
		}
	}
	return count;
}

int main(){
    
}