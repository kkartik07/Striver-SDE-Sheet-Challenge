#include<bits/stdc++.h>
bool bfs(vector<int> adj[],vector<int>& vis,int node){
	vis[node]=0;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int i=q.front();
		q.pop();
		for(auto it:adj[i]){
			if(vis[it]==-1){
				vis[it]=!vis[i];
				q.push(it);
			}
			else if(vis[it]==vis[i])return false;
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	vector<int> adj[edges.size()];
	for(int i=0;i<edges.size();i++){
		for(int j=0;j<edges[0].size();j++){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> vis(edges.size(),-1);
	for(int i=0;i<edges.size();i++){
		if(vis[i]==-1){
			return bfs(adj,vis,i);
		}
	}
}