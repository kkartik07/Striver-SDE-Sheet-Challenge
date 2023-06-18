
vector<int> getTopView(TreeNode<int> *root) {
        //    Write your code here.
    map<int,int> mp;
    vector<int> ans;
    if(root==NULL)return ans;
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(mp.find(it.second.first)==mp.end())mp[it.second.first]=it.first->val;
        if(it.first->left!=NULL)q.push({it.first->left,{it.second.first-1,it.second.second+1}});
        if(it.first->right!=NULL)q.push({it.first->right,{it.second.first+1,it.second.second+1}});
    }

    for(auto it1:mp){
                ans.push_back(it1.second);
    }
    return ans;

}

