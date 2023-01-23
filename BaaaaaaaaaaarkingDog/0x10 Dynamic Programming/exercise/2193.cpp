#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long dp[100][2];
  cin >> n;
  dp[1][0] = 0;
  dp[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }
  cout << dp[n][0] + dp[n][1];
  return 0;
}