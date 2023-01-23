#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    int coin[25];
    int dp[10'005];
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> coin[i];
    cin >> m;
    fill(dp, dp + m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = coin[i]; j <= m; ++j) {
        dp[j] += dp[j - coin[i]];
      }
    }
    cout << dp[m] << '\n';
  }
  return 0;
}