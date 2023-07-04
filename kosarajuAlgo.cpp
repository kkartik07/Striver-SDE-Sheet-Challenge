#include<bits/stdc++.h>
void dfs(int i,vector<int> &vis,stack<int> &st,vector<vector<int>> &adj){
    vis[i]=1;
    for(auto it: adj[i]){
        if(!vis[it])dfs(it,vis,st,adj);
    }
    st.push(i);
}

void dfs2(int curr,vector<vector<int>>&adj,vector<int>&tmp,vector<int>&vis) {
    vis[curr]=true;
    tmp.push_back(curr);
    for(auto it:adj[curr]) {
        if(!vis[it]) {
            dfs2(it,adj,tmp,vis);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    vector<vector<int>> adj2(n);
    for(int i=0;i<edges.size();i++){
        adj2[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;

    for(int i=0;i<n;i++)vis[i]=0;

    while(!st.empty()) {
        int node=st.top();
        st.pop();
        if(!vis[node]) {
            vector<int>tmp;
            dfs2(node,adj2,tmp,vis);
            ans.push_back(tmp);
        }
    }

    return ans;


}