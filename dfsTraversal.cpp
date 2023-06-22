void dfs(vector<int> adj_list[],vector<int>& ans,vector<int>& vis,int node){
    if(!vis[node]){
        vis[node]=1;
        ans.push_back(node);
        for(auto it: adj_list[node]){
            if(!vis[it])dfs(adj_list,ans,vis,it);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj_list[V];
    for(int i= 0; i < E; i++){
        adj_list[edges[i][0]].push_back(edges[i][1]);
        adj_list[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(V,0);
    vector<vector<int>> ans;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(adj_list,temp,vis,i);
            ans.push_back(temp);
        }
    }
    return ans;

}