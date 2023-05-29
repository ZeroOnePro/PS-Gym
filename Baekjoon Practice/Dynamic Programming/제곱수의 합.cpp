#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> dp(n + 1);

  for (int i = 1; i <= n; ++i) {
    dp[i] = i;
    for (int j = 1; j * j <= i; ++j) {
      if (dp[i] > dp[i - j * j] + 1) {
        dp[i] = dp[i - j * j] + 1;
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}