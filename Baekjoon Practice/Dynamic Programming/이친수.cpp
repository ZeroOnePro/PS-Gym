#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;

  vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
  // 0 으로 시작하지 x
  dp[1][0] = 0;
  dp[1][1] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= 1; ++j) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
      } else {
        // 11은 연속 불가능
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }

  cout << dp[n][0] + dp[n][1] << '\n';

  return 0;
}