#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> &a, int n) {
  stack<int> s;
  vector<int> leftSmall(n + 1, -1),
      rightSmall(n + 1, n); // it gives us length of every substring

  for (int i = 0; i < n; i++) {
    while (!s.empty() and a[s.top()] >= a[i])
      s.pop();
    if (!s.empty())
      leftSmall[i] = s.top();
    s.push(i);
  }

  while (!s.empty())
    s.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() and a[s.top()] >= a[i])
      s.pop();
    if (!s.empty())
      rightSmall[i] = s.top();
    s.push(i);
  }

  vector<int> ans(n + 1, INT_MIN), res(n);
  for (int i = 0; i < n; i++) {
    int len =
        rightSmall[i] - leftSmall[i] - 1; // -1 because if len got beyond the
                                          // boundary then it will throws error
    ans[len] = max(ans[len], a[i]);
  }

  for (int i = n - 1; i >= 1; i--)
    ans[i] = max(ans[i], ans[i + 1]);

  for (int i = 1; i <= n; i++)
    res[i - 1] = ans[i];

  return res;
}