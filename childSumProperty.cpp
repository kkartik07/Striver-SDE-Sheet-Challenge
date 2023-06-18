void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL)return;
    int child=0;
    if(root->left!=NULL)child+=root->left->data;
    if(root->right!=NULL)child+=root->right->data;
    
    if(child>=root->data)root->data=child;
    else{
        if(root->left!=NULL)root->left->data=root->data;
        if(root->right!=NULL)root->right->data=root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total=0;
    if(root->left!=NULL)total+=root->left->data;
    if(root->right!=NULL)total+=root->right->data;
    if(root->left || root->right)root->data=total;

}  