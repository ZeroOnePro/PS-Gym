#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  int stair[n + 1], dp[n + 1];
  for (int i = 1; i <= n; ++i) cin >> stair[i];
  int total = accumulate(stair + 1, stair + n + 1, 0);
  if (n <= 2) {
    cout << total << '\n';
    return 0;
  }
  for (int i = 1; i <= 3; ++i) dp[i] = stair[i];
  for (int i = 4; i <= n - 1; ++i) {
    dp[i] = min(dp[i - 2], dp[i - 3]) + stair[i];
  }
  cout << total - min(dp[n - 2], dp[n - 1]) << '\n';
  return 0;
}