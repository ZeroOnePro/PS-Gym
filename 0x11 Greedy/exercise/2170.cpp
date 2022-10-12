#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> l;
  for (int i = 0; i < n; ++i) {
    int st, en;
    cin >> st >> en;
    l.push_back({st, en});
  }
  sort(l.begin(), l.end());
  int cur = 0, len = 0, ans = 0;
  while (cur < n) {
    auto [st, en] = l[cur];
    while (cur < n && l[cur].x <= en) {
      cur += 1;
      if (l[cur].x <= en && l[cur].y > en) en = l[cur].y;
      len = (en - st);
    }
    ans += len;
  }
  cout << ans;
  return 0;
}