#include <bits/stdc++.h>

using namespace std;

const int range = 1e5 + 5;
const int r = 1'000'000'009;
long long dp[range];
int n;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  dp[0] = dp[1] = 1;
  dp[2] = dp[3] = 2;
  for (int i = 4; i <= range; ++i) {
    if (i >= 2) dp[i] += dp[i - 2] % r;
    if (i >= 4) dp[i] += dp[i - 4] % r;
    if (i >= 6) dp[i] += dp[i - 6] % r;
    dp[i] %= r;
  }
  while (tc--) {
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}