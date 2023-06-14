
#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void help(TreeNode* node,vector<int> &ans){
    if(node==NULL)return;
    help(node->left,ans);
    help(node->right,ans);
    ans.push_back(node->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{   
    vector<int> ans;
    help(root,ans);
    return ans;
}