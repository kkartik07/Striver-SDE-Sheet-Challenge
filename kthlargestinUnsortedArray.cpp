#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int k)
{
	// Write your code here.
	if(k>size)return -1;
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=0;i<size;i++){
		q.push(arr[i]);
		if(q.size()>k)q.pop();
	}
	
	return q.top();
}