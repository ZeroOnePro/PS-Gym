#include <bits/stdc++.h>

using namespace std;

int coin[105];
int dp[100'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  fill(dp, dp + 10'005, 10'005);
  for (int i = 0; i < n; ++i) {
    cin >> coin[i];
    dp[coin[i]] = 1;
  }
  for (int i = 0; i < n; ++i)
    for (int j = coin[i]; j <= k; ++j) dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
  cout << (dp[k] == 10'005 ? -1 : dp[k]);
  return 0;
}