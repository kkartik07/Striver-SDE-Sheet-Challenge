#include<bits/stdc++.h>

int dp[104][10004];
/* int solve(int e, int f) {
    if(f == 1 or f == 0)
        return f;
    
    if(e == 1)
        return f; // if onyl one egg is left then u have to check every floor;

    if(dp[e][f] != -1)
        return dp[e][f];

    int low = 1, high = f, ans = 1e9;
    while(low <= high) {
        int mid = (low + high) >> 1;
        int down = solve(e - 1, mid - 1); // egg break at mid, floors left is mid - 1
        int up = solve(e, f - mid); // no egg break, floors left are no.of floors - mid

        ans = min(ans, 1 + max(down, up));
        if(down < up)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return dp[e][f] = ans;
}

int cutLogs(int k, int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(k, n); // k -> eggs, n -> floor
} */


/* int cutLogs(int k, int n) {
    memset(dp, 0, sizeof(dp));
    for(int e = 1; e <= k; e++)
        dp[e][1] = 1;

    for(int f = 1; f <= n; f++)
        dp[1][f] = f;

    for(int e = 2; e <= k; e++) {
        for(int f = 2; f <= n; f++) {
            int low = 1, high = f, ans = INT_MAX;
            while(low <= high) {
                int mid = (low + high) >> 1;
                int down = dp[e - 1][mid - 1];
                int up = dp[e][f - mid];

                ans = min(ans, 1 + max(down, up));
                if(up > down)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }

            dp[e][f] = ans;
        }
    }
    
    return dp[k][n];
} */

int cutLogs(int k, int n) {
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    prev[1] = 1;

    for(int f = 1; f <= n; f++)
        prev[f] = curr[f] = f;

    for(int e = 2; e <= k; e++) {
        for(int f = 2; f <= n; f++) {
            int low = 1, high = f, ans = INT_MAX;
            while(low <= high) {
                int mid = (low + high) >> 1;
                int down = prev[mid - 1];
                int up = curr[f - mid];

                ans = min(ans, 1 + max(down, up));
                if(up > down)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }

            curr[f] = ans;
        }
        prev = curr;
    }
    
    return prev[n];
}