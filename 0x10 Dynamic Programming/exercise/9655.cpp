#include <bits/stdc++.h>

using namespace std;

int dp[1'005];
string p[2] = {"SK", "CY"};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  // 상근 0, 창영 1
  dp[2] = 1;
  for (int i = 3; i <= n; ++i) dp[i] = 1 - dp[i - 1];
  cout << p[dp[n]];
  return 0;
}