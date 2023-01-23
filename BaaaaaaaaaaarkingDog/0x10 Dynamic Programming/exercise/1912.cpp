#include <bits/stdc++.h>

using namespace std;

const int range = 1e6 + 5;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int seq[range];
  int dp[range];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> seq[i];
  dp[0] = seq[0];
  for (int i = 1; i < n; ++i) dp[i] = max(dp[i - 1] + seq[i], seq[i]);
  cout << *max_element(dp, dp + n);
  return 0;
}