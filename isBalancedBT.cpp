#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/

int help(BinaryTreeNode<int>* root){
    if(root==NULL)return 0;

    int lh=help(root->left);
    int rh=help(root->right);
    if(abs(lh-rh)>1 || lh==-1 || rh==-1)return -1;
    return 1+max(lh,rh);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root==NULL)return true;
    if(help(root)==-1)return false;
    return true;
}