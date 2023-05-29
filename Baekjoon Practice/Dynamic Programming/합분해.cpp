#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const long long lim = 1000000000LL;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;

  vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));

  dp[0][0] = 1LL;

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int l = 0; l <= j; ++l) {
        dp[i][j] += dp[i - 1][j - l];
        dp[i][j] %= lim;
      }
    }
  }

  cout << dp[k][n] % lim << '\n';

  return 0;
}