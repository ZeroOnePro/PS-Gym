#include <bits/stdc++.h>

using namespace std;

long long dp[105];

void padovan(void) {
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;
  for (int i = 6; i <= 100; ++i) dp[i] = dp[i - 1] + dp[i - 5];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  padovan();
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}