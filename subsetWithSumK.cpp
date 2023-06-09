void help(vector<int> &arr, vector<vector<int>> &ans, int ind, int n, int k,vector<int> &ds){
    if(ind==n){
        if(k==0)ans.push_back(ds);
        return;
    }
    ds.push_back(arr[ind]);
    help(arr, ans, ind + 1, n, k - arr[ind], ds);
    ds.pop_back();
    help(arr,ans,ind+1,n,k,ds);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    // sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    help(arr,ans,0,n,k,ds);
    return ans;
}