#include <bits/stdc++.h>
int recur(int ind, int w, vector<int>&wt, vector<int>&price, vector<vector<int>>&dp){
	if(w == 0){
		return 0;
	}
	if(ind == 0){
		return (w/wt[ind])*price[0];
	}
	if(dp[ind][w] != -1){
		return dp[ind][w];
	}
	int nottake = recur(ind-1,w,wt, price,dp);
	int take = 0;
	if(w>=wt[ind]){
		take = price[ind] + recur(ind,w-wt[ind],wt,price,dp);
	}
	return dp[ind][w] = max(take,nottake);
}

int cutRod(vector<int> &price, int n){
	vector<int> wt;
	for(int i =1;i<=n;i++){
		wt.push_back(i);
	}
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return recur(n-1,n,wt,price,dp);

}