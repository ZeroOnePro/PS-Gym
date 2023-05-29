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
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (dp[i] == -1 || dp[i] > dp[i - j] + p[j]) {
        dp[i] = dp[i - j] + p[j];
      }
    }
  }

  cout << dp[n] << '\n';
  return 0;
}