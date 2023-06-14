#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *> q;
    vector<int> ans;
    if(root==NULL)return ans;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *temp=q.front();
        q.pop();
        ans.push_back(temp->val);
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
    }
    return ans;
}