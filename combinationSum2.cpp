#include<bits/stdc++.h>
void cs2(vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds,int ind,int n,int sum, int target){
	if(ind==n){
		if(sum==target){
			ans.push_back(ds);
		}
		return;
	}
	if(arr[ind]+sum<=target){
		ds.push_back(arr[ind]);
		cs2(arr,ans,ds,ind+1,n,sum+arr[ind],target);
		ds.pop_back();
	}
	while(ind<n-1 && arr[ind+1]==arr[ind])ind++;
	cs2(arr,ans,ds,ind+1,n,sum,target);
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	vector<int> ds;
	cs2(arr,ans,ds,0,n,0,target);
	// sort(ans.begin(),ans.end());
	
	return ans;
}
