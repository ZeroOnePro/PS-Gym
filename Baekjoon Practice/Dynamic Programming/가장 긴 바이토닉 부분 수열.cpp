#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq(n + 1);
  vector<int> dp(n + 1, 1);
  vector<int> rdp(n + 1, 1);

  for (int i = 1; i <= n; ++i) {
    cin >> seq[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
  }

  for (int i = n; i >= 1; --i) {
    for (int j = n; j >= i; --j) {
      if (seq[j] < seq[i] && rdp[i] < rdp[j] + 1) {
        rdp[i] = rdp[j] + 1;
      }
    }
  }

  int ans = 0;

  for (int i = 0; i <= n; ++i) {
    if (ans < dp[i] + rdp[i] - 1)
      ans = dp[i] + rdp[i] - 1;
  }

  cout << ans << '\n';

  return 0;
}