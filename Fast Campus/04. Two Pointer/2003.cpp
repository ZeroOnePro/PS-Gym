#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  for (auto& pt : s) cin >> pt;
  int en = 0, sum = 0, ans = 0;
  for (int st = 0; st < n; ++st) {
    while (en < n && sum + s[en] <= m) {
      sum += s[en];
      en += 1;
    }
    if (sum == m) ans += 1;
    sum -= s[st];
  }
  cout << ans;
  return 0;
}