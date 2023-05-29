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
  vector<vector<ll>> dp(1001, vector<ll>(11));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 10; ++j) {
      dp[1][j] = 1;
      for (int k = 0; k <= j; ++k) {
        dp[i][j] += dp[i - 1][k];
        dp[i][j] %= 10007;
      }
    }
  }
  ll sum = 0;
  for (int j = 0; j < 10; ++j) {
    sum += dp[n][j];
    sum %= 10007;
  }
  cout << sum << '\n';
  return 0;
}