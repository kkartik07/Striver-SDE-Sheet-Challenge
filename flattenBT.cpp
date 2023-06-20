
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *curr=root;
    stack<TreeNode<int>* >st;
    st.push(curr);
    while(!st.empty()){
        curr=st.top();
        st.pop();
        if(curr->right!=NULL)st.push(curr->right);
        if(curr->left!=NULL)st.push(curr->left);
        if(!st.empty())curr->right=st.top();
        curr->left=NULL;
    }
    return root;
}