#include <bits/stdc++.h>
int dp[104];

bool isPalindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int solve(int ind, int n, string str) {
  if (ind == n)
    return 0;

  if (dp[ind] != -1)
    return dp[ind];

  int mini = INT_MAX;
  for (int k = ind; k < n; k++) {
    if (isPalindrome(str.substr(ind, k - ind + 1)))
      mini = min(mini, 1 + solve(k + 1, n, str));
  }

  return dp[ind] = mini;
}

int palindromePartitioning(string str) {
  int n = str.size();
  memset(dp, -1, sizeof(dp));
  return solve(0, n, str) - 1; // at last there is partition
}

// int palindromePartitioning(string str) {
//   int n = str.size();
//   memset(dp, 0, sizeof(dp));

//   for (int i = n - 1; i >= 0; i--) {
//     int mini = INT_MAX;
//     for (int k = i; k < n; k++)
//       if (isPalindrome(str.substr(i, k - i + 1)))
//         mini = min(mini, 1 + dp[k + 1]);

//     dp[i] = mini;
//   }

//   return dp[0] - 1;
// }