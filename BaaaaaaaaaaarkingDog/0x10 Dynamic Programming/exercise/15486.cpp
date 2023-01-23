#include <bits/stdc++.h>

using namespace std;

const int range = 1e7 + 5 * 1e6 + 5;

int t[range];
int p[range];
int dp[range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i] >> p[i];
  for (int i = 1; i <= n; ++i) {
    dp[i] = max(dp[i], dp[i - 1]);
    if (i + t[i] <= n + 1) dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
  }
  cout << max(dp[n], dp[n + 1]);
  return 0;
}