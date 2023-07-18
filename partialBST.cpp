#include <bits/stdc++.h> 

bool valid(BinaryTreeNode<int> *root, long long minVal, long long maxVal) {
    if(!root)
        return true;

    if(root->data < minVal or root->data > maxVal)
        return false;
    
    return valid(root->left, minVal, root->data) and valid(root->right, root->data, maxVal);
}

bool validateBST(BinaryTreeNode<int> *root) {
    return valid(root, LONG_MIN, LONG_MAX);
}