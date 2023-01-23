#include <bits/stdc++.h>

using namespace std;

const int range = 1005;

int seq[range];
int dp[range];
int pre[range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int mx = 0, cur = -1;
  stack<int> s;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> seq[i];
  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    pre[i] = i;
    for (int j = i; j >= 0; --j) {
      if (seq[i] > seq[j]) {
        dp[i] = max(dp[j] + 1, dp[i]);
        if (dp[i] == dp[j] + 1) pre[i] = j;
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (mx < dp[i]) {
      mx = dp[i];
      cur = i;
    }
  while (pre[cur] != cur) {
    s.push(cur);
    cur = pre[cur];
  }
  s.push(cur);
  cout << mx << '\n';
  while (!s.empty()) {
    cout << seq[s.top()] << ' ';
    s.pop();
  }
  return 0;
}