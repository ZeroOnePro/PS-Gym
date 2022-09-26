#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    int sticker[100'005][5];
    int dp[100'005][5];
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
      if (i <= n)
        cin >> sticker[i][1];
      else
        cin >> sticker[i - n][2];
    }
    dp[1][1] = sticker[1][1];
    dp[1][2] = sticker[1][2];
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= 2; ++j) {
        dp[i][j] =
            max({dp[i - 1][3 - j], dp[i - 2][1], dp[i - 2][2]}) + sticker[i][j];
      }
    }
    cout << max(dp[n][1], dp[n][2]) << '\n';
  }
  return 0;
}