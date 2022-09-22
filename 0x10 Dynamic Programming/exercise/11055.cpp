#include <bits/stdc++.h>

using namespace std;

const int range = 1005;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int seq[range];
  int dp[range];
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> seq[i];
    dp[i] = seq[i];
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = i - 1; j >= 1; --j) {
      if (seq[i] > seq[j]) {
        dp[i] = max(dp[j] + seq[i], dp[i]);
      }
    }
  }
  // for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
  cout << *max_element(dp + 1, dp + n + 1);
  return 0;
}