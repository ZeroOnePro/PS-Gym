#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n);
  vector<bool> is_used(100'002);
  for (auto& pt : s) cin >> pt;
  int en = 0;
  ll ans = 0;
  for (int st = 0; st < n; ++st) {
    while (en < n && !is_used[s[en]]) {
      is_used[s[en]] = true;
      en += 1;
    }
    ans += en - st;
    is_used[s[st]] = false;
  }
  cout << ans;
  return 0;
}