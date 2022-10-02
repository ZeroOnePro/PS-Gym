#include <bits/stdc++.h>

using namespace std;

bool dp[1'005];
string player[2] = {"SK", "CY"};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  dp[0] = 1;
  dp[2] = 1;
  for (int i = 4; i <= n; ++i)
    dp[i] = ((1 - dp[i - 4]) + (1 - dp[i - 3]) + (1 - dp[i - 1]) >= 3);
  cout << player[dp[n]];
  return 0;
}