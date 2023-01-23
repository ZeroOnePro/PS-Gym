#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int div = 1'000'000'000;
  cin >> n;
  long long dp[105][15];
  dp[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 9; ++j) {
      if (i == 1) {
        if (j != 0) dp[i][j] = 1;
        continue;
      }
      if (j == 0)
        dp[i][j] = dp[i - 1][j + 1] % div;
      else if (j == 9)
        dp[i][j] = dp[i - 1][j - 1] % div;
      else
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % div;
    }
  }
  long long cnt = 0;
  for (int i = 0; i <= 9; ++i) cnt += dp[n][i];
  cout << (cnt % div);
  return 0;
}