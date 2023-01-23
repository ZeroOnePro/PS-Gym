#include <bits/stdc++.h>

using namespace std;

const int range = 1005;
const int mod = 1e9 + 3;

int dp[range][range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) dp[i][1] = i;
  for (int i = 4; i <= n; ++i)
    for (int j = 2; j <= min(k, i / 2); ++j)
      dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
  cout << dp[n][k];
  return 0;
}