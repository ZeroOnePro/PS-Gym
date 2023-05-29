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
  vector<vector<int>> cost(1001, vector<int>(3));
  vector<vector<int>> dp(1001, vector<int>(3));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> cost[i][j];
    }
  }
  int ans = 1000 * 1000 + 1;
  for (int k = 0; k <= 2; ++k) {
    for (int j = 0; j <= 2; ++j) {
      if (j == k)
        dp[1][j] = cost[1][j];
      // 못 골라지게 존나 큰 값 집어넣음..
      else
        dp[1][j] = ans;
    }
    // i 2부터 시작해야 첫째집은 사용자가 골라줘야함 => "고정"!
    for (int i = 2; i <= n; ++i) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
      dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
    }
    for (int j = 0; j <= 2; ++j) {
      if (j == k)
        continue;
      ans = min(ans, dp[n][j]);
    }
  }
  cout << ans << '\n';
  return 0;
}