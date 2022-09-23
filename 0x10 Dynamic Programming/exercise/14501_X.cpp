#include <bits/stdc++.h>

using namespace std;

const int range = 20;

int t[range];
int p[range];
int dp[range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i] >> p[i];
  for (int i = n; i >= 1; --i) {
    // i + 1일의 상담을 고르는 것이 더 최대라면 i일은 거른다
    if (i + t[i] <= n + 1)
      dp[i] = max(dp[i + t[i]] + p[i], dp[i + 1]);
    else
      dp[i] = dp[i + 1];
  }
  cout << *max_element(dp + 1, dp + n + 1);
  return 0;
}