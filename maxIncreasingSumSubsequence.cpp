 #include <bits/stdc++.h> 
    int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
    {
       int ans=arr[0];
       vector<int>dp=arr;
       for (int i=1;i<n;i++)
       {
           for (int j=0;j<i;j++)
           {
               if (arr[i]>arr[j])
               {
                   if (dp[j]+arr[i]>dp[i])
                   {
                       dp[i]=dp[j]+arr[i];
                   }
               }
           }
           ans=max(ans,dp[i]);
       }
       return ans;

    }