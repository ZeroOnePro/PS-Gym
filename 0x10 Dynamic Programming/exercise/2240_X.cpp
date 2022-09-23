#include <bits/stdc++.h>

using namespace std;

int s[1005];
int dp[1005][35];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, w;
  cin >> n >> w;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      if (j == 0) dp[i][j] += (s[i] == 1);
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + (1 + j % 2 == s[i]);
    }
  }
  cout << *max_element(dp[n], dp[n] + w + 1);
  return 0;
}