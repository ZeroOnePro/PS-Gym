#include <bits/stdc++.h>

using namespace std;

const int range = 1030;

int board[range][range];
int dp[range][range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> board[i][j];
  for (int i = 1; i <= n; ++i) {
    dp[1][i] = board[1][i];
    for (int j = 2; j <= n; ++j) {
      dp[j][i] = dp[j - 1][i] + board[j][i];
    }
  }
  while (m--) {
    int x1, y1, x2, y2, sum = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2)
      sum = board[x1][y1];
    else if (x1 == 1 && y1 == 1 && x2 == n && y2 == n)
      for (int i = 1; i <= n; ++i) sum += dp[n][i];
    else
      for (int i = y1; i <= y2; ++i) sum += (dp[x2][i] - dp[x1 - 1][i]);
    cout << sum << '\n';
  }
  return 0;
}