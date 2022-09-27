#include <bits/stdc++.h>

using namespace std;

int coin[100];
int dp[10'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> coin[i];
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = coin[i]; j <= k; ++j) {
      dp[j] += dp[j - coin[i]];
    }
  }
  cout << dp[k];
  return 0;
}