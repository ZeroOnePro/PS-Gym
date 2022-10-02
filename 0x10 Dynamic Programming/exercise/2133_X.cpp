#include <bits/stdc++.h>

using namespace std;

long long dp[35];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  dp[2] = 3;
  for (int i = 4; i <= n; i += 2) {
    dp[i] = 3 * dp[i - 2];
    for (int j = 2; j <= i - 4; j += 2) dp[i] += 2 * dp[j];
    dp[i] += 2;
  }
  cout << dp[n];
  return 0;
}