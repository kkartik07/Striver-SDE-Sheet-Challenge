
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil=-1;
    while(node!=NULL){
        if(node->data==x)return x;
        else if(node->data>x){
            ceil=node->data;
            node=node->left;
        }
        else node=node->right;
    }
    return ceil;
}