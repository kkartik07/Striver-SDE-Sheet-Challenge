void rec(TreeNode<int> *root, int x,vector<int>&ans)
{
    if(!root)
    return;
    ans.push_back(root->data);
    if(root->data==x)
    return;
    rec(root->left,x,ans);
    rec(root->right,x,ans);
    if(ans[ans.size()-1]!=x)
    ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    if(!root)
    return {};
    vector<int>ans;
    rec(root,x,ans);
    return ans;
}