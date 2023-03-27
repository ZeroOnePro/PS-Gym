#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int range = 105;

int n;
ll dp[range][range];
ll board[range][range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i + board[i][j] < n) {
        if (i + board[i][j] == n - 1 && j == n - 1 && board[i][j] == 0)
          continue;
        dp[i + board[i][j]][j] += dp[i][j];
      }
      if (j + board[i][j] < n) {
        if (j + board[i][j] == n - 1 && i == n - 1 && board[i][j] == 0)
          continue;
        dp[i][j + board[i][j]] += dp[i][j];
      }
    }
  cout << dp[n - 1][n - 1];
  return 0;
}