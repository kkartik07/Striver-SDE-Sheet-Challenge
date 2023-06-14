
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
    ans.push_back(node->data);
    help(node->left,ans);
    help(node->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{   
    vector<int> ans;
    help(root,ans);
    return ans;
}