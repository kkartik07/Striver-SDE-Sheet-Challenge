#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int> res;
	priority_queue<int> maxi;
	priority_queue<int,vector<int>,greater<int>> mini;
	for(int i=0; i < n ; i++){
		maxi.push(arr[i]);
		mini.push(arr[i]);
		if(maxi.size() > k) maxi.pop();
		if(mini.size()> k) mini.pop();
	}
	return {maxi.top(),mini.top()};
}	