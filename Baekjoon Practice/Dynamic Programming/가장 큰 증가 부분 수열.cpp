#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq(1001);
  vector<int> dp(1001);
  for (int i = 1; i <= n; ++i) {
    cin >> seq[i];
  }

  for (int i = 1; i <= n; ++i) {
    dp[i] = seq[i];
    for (int j = 1; j < i; ++j) {
      if (seq[j] < seq[i] && dp[i] < dp[j] + seq[i]) {
        dp[i] = seq[i] + dp[j];
      }
    }
  }

  int ans = dp[1];
  for (int i = 2; i <= n; ++i) {
    if (ans < dp[i]) {
      ans = dp[i];
    }
  }
  cout << ans << '\n';
  return 0;
}