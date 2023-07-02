#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) {
  vector<int> ans;
  int i = 0, j = 0, n = arr.size();
  unordered_map<int, int> mp;

  while (j < n) {
    mp[arr[j]]++;
    if (j - i + 1 < k)
      j++;
    else if (j - i + 1 == k) {
      ans.push_back(mp.size());
      
      mp[arr[i]]--;
      if (mp[arr[i]] == 0)
        mp.erase(arr[i]);
      
      i++, j++;
    }
  }

  return ans;
}