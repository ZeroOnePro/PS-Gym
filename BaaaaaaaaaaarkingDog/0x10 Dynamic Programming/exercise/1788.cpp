#include <bits/stdc++.h>

using namespace std;

int dp[1'000'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int in, mod = 1'000'000'000;
  cin >> in;
  dp[0] = 0;
  dp[1] = 1;
  int n = in < 0 ? in * -1 : in;
  for (int i = 2; i <= n; ++i) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  if (in < 0)
    cout << (in % 2 == 0 ? -1 : 1) << '\n';
  else
    cout << (in > 0) << '\n';
  cout << dp[n];
  return 0;
}