#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[70][10];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc, n;
  for (int i = 0; i < 10; ++i) dp[1][i] = 1;
  for (int i = 2; i <= 64; ++i)
    for (int j = 0; j < 10; ++j)
      for (int k = 0; k <= j; ++k) dp[i][j] += dp[i - 1][k];
  cin >> tc;
  while (tc--) {
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < 10; ++i) ans += dp[n][i];
    cout << ans << '\n';
  }
  return 0;
}