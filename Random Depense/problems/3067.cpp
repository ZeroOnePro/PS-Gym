#include <bits/stdc++.h>

using namespace std;

const int range = 1e4;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    vector<int> coin(n);
    vector<int> dp(range + 5, 0);
    for (auto& pt : coin) cin >> pt;
    cin >> m;
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
      for (int j = 1; j <= m; ++j)
        if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
    cout << dp[m] << '\n';
  }
  return 0;
}