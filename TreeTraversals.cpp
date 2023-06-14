#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void Inorderhelp(BinaryTreeNode<int>* node,vector<int> &ans){
    if(node==NULL)return;
    Inorderhelp(node->left,ans);
    ans.push_back(node->data);
    Inorderhelp(node->right,ans);
}
void Preorderhelp(BinaryTreeNode<int>* node,vector<int> &ans){
    if(node==NULL)return;
    ans.push_back(node->data);
    Preorderhelp(node->left,ans);
    Preorderhelp(node->right,ans);
}
void Postorderhelp(BinaryTreeNode<int>* node,vector<int> &ans){
    if(node==NULL)return;
    Postorderhelp(node->left,ans);
    Postorderhelp(node->right,ans);
    ans.push_back(node->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> tempans;
    Inorderhelp(root,tempans);
    ans.push_back(tempans);
    tempans.clear();
    Preorderhelp(root,tempans);
    ans.push_back(tempans);
    tempans.clear();
    Postorderhelp(root,tempans);
    ans.push_back(tempans);
    return ans;
}
