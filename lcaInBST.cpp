
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here

    // Iterative Approach
    TreeNode<int>* curr = root;
    
    while(curr != NULL){
        if(curr->data > P->data && curr->data > Q->data) curr = curr->left;
        else if(curr->data < P->data && curr->data < Q->data) curr = curr->right;
        else return curr;
    }

    return NULL;
}