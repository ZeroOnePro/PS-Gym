#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int tri[505][505];
  int dp[505][505];
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j) cin >> tri[i][j];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) dp[i][j] = dp[i - 1][j] + tri[i][j];
      if (i == j) dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tri[i][j];
    }
  }
  cout << *max_element(dp[n - 1], dp[n - 1] + n) << '\n';
  return 0;
}