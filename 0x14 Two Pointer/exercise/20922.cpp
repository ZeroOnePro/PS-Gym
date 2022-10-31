#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  vector<int> is_used(100'005);
  for (auto& pt : s) cin >> pt;
  int en = 0, mx = 0;
  for (int st = 0; st < n; ++st) {
    while (en < n && is_used[s[en]] + 1 <= k) {
      is_used[s[en]] += 1;
      en += 1;
    }
    mx = max(en - st, mx);
    is_used[s[st]] -= 1;
  }
  cout << mx;
  return 0;
}