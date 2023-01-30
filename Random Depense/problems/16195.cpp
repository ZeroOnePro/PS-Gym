#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int range = 1e3 * 1;
ll r = 1e9 + 9;

int t, n, m;
ll dp[range + 5][range + 5];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  dp[1][1] = dp[2][1] = dp[3][1] = dp[2][2] = dp[3][3] = 1;
  dp[3][2] = 2;
  for (int i = 4; i <= range; ++i)
    for (int j = 2; j <= range; ++j)
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % r;
  while (t--) {
    cin >> n >> m;
    ll sum = 0;
    for (int i = 1; i <= m; ++i) sum += dp[n][i] % r;
    cout << sum % r << '\n';
  }
  return 0;
}