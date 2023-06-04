#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini=INT_MAX,maxProf=0;
    for(int i=0;i<prices.size();i++){
        mini=min(mini,prices[i]);
        maxProf=max(maxProf,prices[i]-mini);
    }
    return maxProf;
}