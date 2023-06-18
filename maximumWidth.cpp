int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)
    return 0;

    queue<pair<TreeNode<int>*, int>>q;
    q.push({root,0});

    int ans=0;
    while(!q.empty())
    {
        int siz = q.size();
        ans=max(ans,siz);
        for(int i=0;i<siz;i++)
        {
            TreeNode<int> *temp = q.front().first;
            int index = q.front().second;
            q.pop();

            if(temp->left)
            q.push({temp->left,2*index+1});

            if(temp->right)
            q.push({temp->right,2*index+2});
        }

        //ans = max(ans, ri-le);
    }
    return ans;

}