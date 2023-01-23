#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, c, m, ans = 0;
  vector<tuple<int, int, int>> del;
  cin >> n >> c >> m;
  vector<int> caps(n, c);
  for (int i = 0; i < m; ++i) {
    int from, to, cap;
    cin >> from >> to >> cap;
    del.push_back({--to, --from, cap});
  }
  sort(del.begin(), del.end());
  for (int i = 0; i < m; ++i) {
    auto [to, from, cap] = del[i];
    int mn = cap;
    for (int j = from; j < to; ++j) mn = min(caps[j], mn);
    for (int j = from; j < to; ++j) caps[j] -= mn;
    ans += mn;
  }
  cout << ans;
  return 0;
}