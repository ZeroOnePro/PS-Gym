#include <algorithm>
#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> dp[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] += max({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
    }
  }

  cout << dp[n][m] << '\n';
  return 0;
}