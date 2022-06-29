#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int dp[11];
  for (int i = 1; i <= 3; ++i) dp[i] = 1 << (i - 1);
  for (int i = 4; i <= 10; ++i) {
    dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
  }
  int test_case;
  cin >> test_case;
  while (test_case--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}