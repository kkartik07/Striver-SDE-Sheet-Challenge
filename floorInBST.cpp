
int floorInBST(TreeNode<int> * root, int X)
{
    int floor=-1;
    // Write your code here.
    while(root!=NULL){
        if(root->val==X)return X;
        else if(root->val>X)root=root->left;
        else{
            floor=root->val;
            root=root->right;
        }
    }
    return floor;
}