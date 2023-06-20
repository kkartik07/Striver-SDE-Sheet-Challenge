#include<bits/stdc++.h>

TreeNode<int>* buildBST(vector<int> &preorder, int &index, int ub = INT_MAX){
    // Recursive Approach
    // Time Complexity: O(N)
    // Space Complexity: O(Height)
    // Base case
    if(preorder.size() <= index || preorder[index] >= ub) return NULL;
    // Build Root
    TreeNode<int>* root = new TreeNode<int>(preorder[index]);
    index++; 
    root->left = buildBST(preorder, index, root->data);
    root->right = buildBST(preorder, index, ub);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Recursive Approach
    int index = 0;
    return buildBST(preOrder, index); 
}