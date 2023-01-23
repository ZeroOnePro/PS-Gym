#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int dp[1005];
  cin >> n;
  dp[1] = 1;
  dp[2] = 3;
  for (int i = 3; i <= n; ++i) dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
  cout << dp[n] << '\n';
  return 0;
}