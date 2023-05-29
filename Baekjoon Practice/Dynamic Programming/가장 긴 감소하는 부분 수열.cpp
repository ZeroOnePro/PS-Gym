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
  for (int i = n; i >= 1; --i) {
    dp[i] = 1;
    for (int j = n; j > i; --j) {
      if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
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