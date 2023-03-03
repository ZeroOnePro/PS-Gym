#include <bits/stdc++.h>

using namespace std;

const int range = 505;

int n;
int dp[range][range];
int sum[range][range];
int file[range];

void init() {
  fill(file, file + range, 0);
  for (int i = 0; i < range; ++i) {
    fill(dp[i], dp[i] + range, INT_MAX);
    fill(sum[i], sum[i] + range, 0);
  }
}

void pro() {
  for (int i = 1; i <= n; ++i) cin >> file[i];
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) {
      if (i == j) {
        sum[i][j] = file[j];
        dp[i][j] = 0;
      } else
        sum[i][j] = sum[i][j - 1] + file[j];
    }
  for (int len = 1; len <= n; ++len)
    for (int i = 1; i <= n - len + 1; ++i) {
      int j = i + len - 1;
      for (int k = i; k < j; ++k)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][j]);
    }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    init();
    pro();
    cout << dp[1][n] << '\n';
  }
  return 0;
}