#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> s;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        if(s.size()==0)ans[i]=-1;
        else if(s.size()>0 && s.top()>arr[i])ans[i]=s.top();
        else if(s.size()>0 && s.top()<=arr[i]){
            while(s.size() && s.top()<=arr[i])s.pop();
            if(s.size()==0)ans[i]=-1;
            else ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    return ans;

}