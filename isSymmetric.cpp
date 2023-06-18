
bool check(BinaryTreeNode<int>* node1,BinaryTreeNode<int>* node2){
    if(node1==NULL && node2==NULL)return true;
    if(node1->data!=node2->data)return false;
    return check(node1->left,node2->right) && check(node1->right,node2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root==NULL)return true;
    return check(root->left,root->right);   
}