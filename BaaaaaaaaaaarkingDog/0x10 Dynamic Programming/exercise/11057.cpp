#include <bits/stdc++.h>

using namespace std;

int dp[1'005][15];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, mod = 10'007;
  cin >> n;
  for (int i = 0; i <= 9; ++i) dp[1][i] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp[i][j] += (dp[i - 1][k] % mod);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 9; ++i) ans += (dp[n][i] % mod);
  ans %= mod;
  cout << ans;
  return 0;
}