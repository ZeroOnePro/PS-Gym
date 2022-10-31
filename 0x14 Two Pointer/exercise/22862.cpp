#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (auto& pt : s) cin >> pt;
  int en = 0, ans = 0, cnt = 0;
  for (int st = 0; st < n; ++st) {
    while (en < n && cnt <= k) {
      if (s[en] & 1) cnt += 1;
      en += 1;
    }
    ans = max(ans, en - st - cnt);
    if (s[st] & 1) cnt -= 1;
  }
  cout << ans;
  return 0;
}