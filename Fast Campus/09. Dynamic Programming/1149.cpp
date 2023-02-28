#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int color[1001][3], dp[1001][3];
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> color[i][j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    dp[1][i] = color[1][i];
  }
  for (int i = 2; i <= n; ++i) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
  }
  cout << min({dp[n][0], dp[n][1], dp[n][2]});
  return 0;
}