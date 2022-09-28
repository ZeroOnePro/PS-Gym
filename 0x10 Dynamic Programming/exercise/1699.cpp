#include <bits/stdc++.h>

using namespace std;

int dp[100'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  fill(dp + 2, dp + n + 1, 100'005);
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  cout << dp[n];
  return 0;
}