#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<ll>> dp(n + 1, vector<ll>(3));
  dp[0][0] = 1;
  dp[0][1] = 1;
  dp[0][2] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i][0] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    dp[i][1] += dp[i - 1][0] + dp[i - 1][2];
    dp[i][2] += dp[i - 1][0] + dp[i - 1][1];
    dp[i][0] %= 9901;
    dp[i][1] %= 9901;
    dp[i][2] %= 9901;
  }
  ll sum = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 9901;
  cout << sum << '\n';
  return 0;
}