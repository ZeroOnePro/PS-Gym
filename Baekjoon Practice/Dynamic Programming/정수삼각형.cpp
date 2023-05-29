#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> triangle(501, vector<int>(501));
  vector<vector<int>> dp(501, vector<int>(501));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> triangle[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (j == 1)
        dp[i][j] += dp[i - 1][j] + triangle[i][j];
      else if (i == j)
        dp[i][j] += dp[i - 1][j - 1] + triangle[i][j];
      else
        dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
    }
  }
  int ans = dp[n][1];
  for (int i = 2; i <= n; ++i) {
    if (ans < dp[n][i]) {
      ans = dp[n][i];
    }
  }

  cout << ans << '\n';
  return 0;
}