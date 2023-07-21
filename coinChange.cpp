#include <bits/stdc++.h>
using namespace std;

/* long solve(int ind, int *denominations, int amt, vector<vector<long>> &dp) {
  if (ind == 0 or amt == 0)
    return amt % denominations[0] == 0;

  if (dp[ind][amt] != -1)
    return dp[ind][amt];

  long notTake = solve(ind - 1, denominations, amt, dp);
  long take = 0;
  if (denominations[ind] <= amt)
    take = solve(ind, denominations, amt - denominations[ind], dp);

  return dp[ind][amt] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
  vector<vector<long>> dp(n, vector<long>(value + 1, -1));
  long val = solve(n - 1, denominations, value, dp);
  return val == 1e9 ? 0 : val;
} */

/* long countWaysToMakeChange(int *denominations, int n, int value) {
  vector<vector<long>> dp(n, vector<long>(value + 1, 0));

  for (int i = 0; i <= value; i++)
    dp[0][i] = value % denominations[0] == 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= value; j++) {
      long notTake = dp[i - 1][j];
      long take = 0;
      if (denominations[i] <= j)
        take = dp[i][j - denominations[i]];

      dp[i][j] = take + notTake;
    }
  }

  return dp[n - 1][value];
} */

long countWaysToMakeChange(int *denominations, int n, int value) {
  vector<long> prev(value + 1, 0), curr(value + 1, 0);

  for (int i = 0; i <= value; i++)
    prev[i] = value % denominations[0] == 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= value; j++) {
      long notTake = prev[j];
      long take = 0;
      if (denominations[i] <= j)
        take = curr[j - denominations[i]];

      curr[j] = take + notTake;
    }
    prev = curr;
  }

  return prev[value];
}