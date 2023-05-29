#include <algorithm>
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
  vector<vector<ll>> price(1001, vector<ll>(3));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> price[i][j];
    }
  }

  vector<vector<ll>> dp(1001, vector<ll>(3));
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + price[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + price[i][1];
    dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + price[i][2];
  }
  ll ans = min({dp[n][0], dp[n][1], dp[n][2]});
  cout << ans << '\n';
  return 0;
}