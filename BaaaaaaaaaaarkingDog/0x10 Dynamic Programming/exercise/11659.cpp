#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, i, j;
  int seq[1000001], dp[1000001];
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> seq[i];
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) dp[i] = dp[i - 1] + seq[i];
  while (m--) {
    cin >> i >> j;
    cout << dp[j] - dp[i - 1] << '\n';
  }
  return 0;
}