unordered_map<graphNode*,graphNode*>v;
graphNode *cloneGraph(graphNode *node)
{
    if(!node) return NULL;
    if(!v.count(node)){
        v[node] = new graphNode(node->data, {});
        for(auto &i : node->neighbours){
            v[node]->neighbours.push_back(cloneGraph(i));
        }
    }    
    return v[node];
}