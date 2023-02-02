#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create adj list
	unordered_map<int, set<int>> adj;

	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].insert(v);
		adj[v].insert(u);
	}
	

	// create parent and visited DS
	unordered_map<int,bool> visited;
	unordered_map<int, int> parent;
	queue<int>q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto neighbour: adj[front]){
			if(!visited[neighbour]){
				visited[neighbour]=true;
				parent[neighbour]=front;
				q.push(neighbour);
			}
		}
	}
	vector<int>ans;
	int currNode=t;
	ans.push_back(currNode);

	while(currNode != s){
		currNode=parent[currNode];
		ans.push_back(currNode);
	}

	int i=0,j=ans.size()-1;

	while(i<=j){
		swap(ans[i++],ans[j--]);

	}
	return ans;
}


int main(){

}