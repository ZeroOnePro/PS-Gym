#include <bits/stdc++.h>

using namespace std;

int dp[1'000'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, mod = 15'746;
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  cout << dp[n];
  return 0;
}