#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    unordered_map<int,pair<int,int>> m;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum=arr[i]+arr[j];
            if(m.find(sum)==m.end()){
                m[sum]={i,j};
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int s=target-arr[i]-arr[j];
            if (m.find(s) != m.end()) {
                int v1 = m[s].first;
                int v2 = m[s].second;
                if (i != v1 && i != v2 && j != v1 && j != v2)
                    return "Yes";
                }
        }
    }
return "No";
}

