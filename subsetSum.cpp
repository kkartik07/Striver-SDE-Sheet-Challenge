#include <bits/stdc++.h> 
void help(vector<int> &num, vector<int> &ans,int sum,int ind,int n){
  if (ind == n) {
    ans.push_back(sum);
    return;
  }
  help(num,ans,sum,ind+1,n);
  help(num,ans,sum+num[ind],ind+1,n);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    help(num,ans,0,0,num.size());
    sort(ans.begin(),ans.end());
    return ans;
}