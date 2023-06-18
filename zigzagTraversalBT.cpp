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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(root==NULL)return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> temp(size);
            BinaryTreeNode<int>* node;
        for(int i=0;i<size;i++){
            node=q.front();
            leftToRight?temp[i]=node->data:temp[size-i-1]=node->data;
            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
            q.pop();
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
        leftToRight=!leftToRight;
    }
    return ans;
}
