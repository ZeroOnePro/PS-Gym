#include <bits/stdc++.h>

using namespace std;

vector<int> vip(1);  // 고정석의 번호
int dp[45];  // 연속된 자리의 개수가 i개일 때 앉을 수 있는 경우의 수

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int v;
    cin >> v;
    vip.push_back(v);
  }
  vip.push_back(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
  int ans = 1;
  for (int i = 1; i < vip.size(); ++i) ans *= dp[vip[i] - vip[i - 1] - 1];
  cout << ans;
  return 0;
}