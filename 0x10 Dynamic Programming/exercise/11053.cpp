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
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
    dp[i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (seq[i] > seq[j]) dp[i] = max(dp[j] + 1, dp[i]);
    }
  }
  cout << *max_element(dp, dp + n);
  return 0;
}