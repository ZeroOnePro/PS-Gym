#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<ll> ans;
  ll mn = 3 * 1e9 + 5;
  cin >> n;
  vector<ll> sol(n);
  for (auto& pt : sol) cin >> pt;
  sort(sol.begin(), sol.end());
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j) {
      ll target = -sol[i] - sol[j];
      int lb = lower_bound(sol.begin(), sol.end(), target) - sol.begin();
      for (int cur = -2; cur <= 2; ++cur) {
        int idx = lb + cur;
        if (idx == i || idx == j) continue;
        if (idx < 0 || idx >= n) continue;
        if (abs(mn) > abs(-target + sol[idx])) {
          mn = abs(-target + sol[idx]);
          ans = {sol[i], sol[j], sol[idx]};
        }
      }
    }
  sort(ans.begin(), ans.end());
  for (ll s : ans) cout << s << ' ';
  return 0;
}