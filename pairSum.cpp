#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;
   map<int,int> mp;

   for(int i=0;i<arr.size();i++){
      if(mp.find(s-arr[i])!=mp.end()){
         int cnt=mp[s-arr[i]];
         while(cnt--){
            vector<int> temp;
            temp.push_back(s-arr[i]);
            temp.push_back(arr[i]);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
         }
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;

}