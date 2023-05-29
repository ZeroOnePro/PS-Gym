#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0);
  dp[0] = 1; // 2를 위해서
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 796796;
  }
  cout << dp[n] << '\n';
  return 0;
}