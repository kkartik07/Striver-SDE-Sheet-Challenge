#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int>ans;
    int min=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>min){
            min=arr[i];
        }
    }

    int x=min;
    int a[x+1]={0};
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }

    int t=0;
    while(k--){
       int  m=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[arr[i]]>m){
                m=a[arr[i]];
                t=arr[i];
            }
        }
        ans.push_back(t);
        a[t]=0;
    }
    sort(ans.begin(),ans.end());
    return ans;
}