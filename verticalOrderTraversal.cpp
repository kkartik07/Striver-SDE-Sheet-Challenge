
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int,map<int,vector<int> > > mp;

    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        mp[it.second.first][it.second.second].push_back(it.first->data);
        if(it.first->left!=NULL)q.push({it.first->left,{it.second.first-1,it.second.second+1}});
        if(it.first->right!=NULL)q.push({it.first->right,{it.second.first+1,it.second.second+1}});
    }

    vector<int> ans;
    for(auto it1:mp){
        for(auto it2:it1.second){
            for(auto it3:it2.second)
                ans.push_back(it3);
        }
    }
    return ans;
}