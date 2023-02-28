#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[105][25];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, target;
  cin >> n;
  vector<int> num(n - 1);
  for (auto& pt : num) cin >> pt;
  cin >> target;
  dp[0][num[0]] = 1;
  for (int i = 1; i <= n - 1; ++i)
    for (int j = 0; j <= 20; ++j) {
      if (j + num[i] >= 0 && j + num[i] <= 20)
        dp[i][j] += dp[i - 1][j + num[i]];
      if (j - num[i] >= 0 && j - num[i] <= 20)
        dp[i][j] += dp[i - 1][j - num[i]];
    }
  cout << dp[n - 2][target];
  return 0;
}