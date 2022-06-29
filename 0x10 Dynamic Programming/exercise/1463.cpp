#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int dp[1000001];
  dp[0] = 0;
  dp[1] = 0;
  int mx = INT_MAX;
  for (int i = 2; i <= n; ++i) {
    dp[i] = min({i % 3 == 0 ? dp[i / 3] + 1 : mx,
                 i % 2 == 0 ? dp[i / 2] + 1 : mx, dp[i - 1] + 1});
  }
  cout << dp[n] << '\n';
  return 0;
}