#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; ++i) {
      dp[1][i] = i;
    }

    for (int i = 2; i <= n; ++i) {
      for (int j = i; j <= m; ++j) {
        for (int k = j; k >= i; --k) {
          dp[i][j] += dp[i - 1][k - 1];
        }
      }
    }
    cout << dp[n][m] << '\n';
  }
  return 0;
}