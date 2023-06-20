bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL)return false;
    while(root!=NULL){
        if(root->data==x)return true;
        if(root->data>x)root=root->left;
        else root=root->right;
    }
    return false;
}