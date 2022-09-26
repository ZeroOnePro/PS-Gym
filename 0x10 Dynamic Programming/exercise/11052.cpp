#include <bits/stdc++.h>

using namespace std;

int p[10'005];
int dp[10'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  dp[1] = p[1];
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] = max(dp[i], dp[i - j] + p[j]);
    }
  }
  cout << dp[n];
  return 0;
}