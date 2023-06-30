#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    // creating adj list;
    vector<pair<int,int>> adj_list[vertices];
    for(auto i: vec){
        adj_list[i[0]].push_back({i[1],i[2]});
        adj_list[i[1]].push_back({i[0],i[2]});
    }

    vector<int> cost(vertices,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    cost[source] = 0;
    pq.push({0,source});

    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();

        for(auto i: adj_list[temp.second]){
            if(temp.first + i.second < cost[i.first]){
                cost[i.first] = temp.first + i.second;
                pq.push({temp.first + i.second,i.first});
            }
        }
    }
    return cost;
}