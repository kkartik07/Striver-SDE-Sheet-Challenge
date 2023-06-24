int dfs(vector<int> adj[],vector<int>& vis,vector<int> &pathvis,int i){
  vis[i]=1;
  pathvis[i]=1;

  for(auto it:adj[i]){
    if(!vis[it]){
      if(dfs(adj,vis,pathvis,it))return 1;
    }
    else if(pathvis[it]==1)return 1;
  }
  pathvis[i]=0;
  return 0;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[n+1];
  for(auto it:edges){
    adj[it.first].push_back(it.second);
  }
  vector<int> vis(n+1,0);
  vector<int> pathvis(n+1,0);

  for(int i=1;i<n+1;i++){
    if(!vis[i]){
      if(dfs(adj,vis,pathvis,i))return 1;
    }
  }
  return 0;
}