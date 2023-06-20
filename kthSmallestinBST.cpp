
int kthSmallest(TreeNode<int> *curr, int k)
{
	//	Write the code here.
    vector < int > inOrder;
    stack <TreeNode<int> * > s;
    while (true) {
        if (curr != NULL) {
        s.push(curr);
        curr = curr -> left;
        } else {
        if (s.empty()) break;
        curr = s.top();
        inOrder.push_back(curr -> data);
        s.pop();
        curr = curr -> right;
        }
    }
  return inOrder[k-1];
}