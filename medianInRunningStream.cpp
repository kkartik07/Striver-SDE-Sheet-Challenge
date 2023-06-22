#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int> pq1;
	priority_queue<int,vector<int>,greater<int>> pq2;

	vector<int> ans;
	ans.push_back(arr[0]);
	pq1.push(arr[0]);
	for(int i=1;i<n;i++){
		int num=arr[i];
		if(pq1.size() > pq2.size()){
			if(num<pq1.top()){
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(num);
			}
			else{
				pq2.push(num);
			}
			ans.push_back((pq1.top()+pq2.top())/2);
		}
		else{
			if(num<pq1.top()){
				pq1.push(num);
			}
			else{
				pq2.push(num);
				pq1.push(pq2.top());
				pq2.pop();
			}
			ans.push_back(pq1.top());
			
		}
	}
		return ans;
}
