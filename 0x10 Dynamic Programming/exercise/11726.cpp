#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int dp[n - 1];
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i)
    // (a + b) mod n = a mod n + b mod n
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
  cout << dp[n] << '\n';
  return 0;
}