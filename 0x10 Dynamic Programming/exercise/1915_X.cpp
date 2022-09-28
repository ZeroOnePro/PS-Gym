#include <bits/stdc++.h>

using namespace std;

string square[1'005];
int dp[1'005][1'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> square[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) dp[i + 1][j + 1] = square[i][j] - '0';
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (square[i - 1][j - 1] == '1') {
        dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
        ans = max(ans, dp[i][j]);
      }
    }
  cout << ans * ans;
  return 0;
}