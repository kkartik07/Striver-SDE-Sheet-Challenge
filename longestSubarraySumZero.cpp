#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  int sum=0;
  int len=0;
  unordered_map<int,int> mp;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (sum == 0)
      len = i + 1;
    else if (mp.find(sum) != mp.end())
      len = max(len, i - mp[sum]);
    else
      mp[sum] = i;
  }
  return len;
}