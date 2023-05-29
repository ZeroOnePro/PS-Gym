#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;

  vector<vector<int>> dp(n + 1, vector<int>(k + 1));

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= min(i, k); ++j) {
      if (j == 0 || j == i) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        dp[i][j] %= 10007;
      }
    }
  }

  cout << dp[n][k] % 10007 << '\n';

  return 0;
}