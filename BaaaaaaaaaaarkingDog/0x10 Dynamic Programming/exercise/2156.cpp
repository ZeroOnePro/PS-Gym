#include <bits/stdc++.h>

using namespace std;

const int range = 10'000;

int wine[range];
int dp[range][3];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> wine[i];
  dp[1][1] = wine[1];
  dp[1][2] = 0;
  dp[2][1] = wine[2];
  dp[2][2] = wine[1] + wine[2];
  for (int i = 3; i <= n; ++i) {
    dp[i][1] =
        max({dp[i - 3][1], dp[i - 3][2], dp[i - 2][1], dp[i - 2][2]}) + wine[i];
    dp[i][2] = dp[i - 1][1] + wine[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, max(dp[i][1], dp[i][2]));
  cout << ans;
  return 0;
}