
#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj_list[vertex];
    for(int i= 0; i < edges.size(); i++){
        adj_list[edges[i].first].push_back(edges[i].second);
        adj_list[edges[i].second].push_back(edges[i].first);
    }
    // since in test case we want output in lexicographically order
    for(int i = 0; i < vertex; i++){
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    vector<int> vis(vertex,0);
    vector<int> bfs;
    for(int i = 0; i < vertex ; i++){
        queue<int> q;
        if(vis[i]==0){
            q.push(i);
            vis[i]=1;
            bfs.push_back(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it: adj_list[node]){
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                        bfs.push_back(it);
                    }
                }
            }
        }
    }
    return bfs;
}