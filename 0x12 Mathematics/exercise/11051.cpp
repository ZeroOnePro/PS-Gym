#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int dp[1002][1002];
  for (int i = 1; i <= 1000; ++i) {
    dp[i][0] = dp[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      dp[i][j] = (dp[i - 1][k] + dp[i - 1][k - 1]) % 10007;
    }
  }
  int n, m;
  cin >> n >> m;
  cout << dp[n][m];
  return 0;
}