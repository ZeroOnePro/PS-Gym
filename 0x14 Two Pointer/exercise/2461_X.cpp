#include <bits/stdc++.h>

using namespace std;

#define cap first
#define num second

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> s;
  vector<int> is_used(n + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < m; ++j) {
      int in;
      cin >> in;
      s.push_back({in, i});
    }
  sort(s.begin(), s.end());
  int st = 0, tot = 0, mn = INT_MAX;
  for (int en = 0; en < n * m; ++en) {
    if (is_used[s[en].num] == 0) tot += 1;
    is_used[s[en].num] += 1;
    while (tot == n) {
      mn = min(mn, s[en].cap - s[st].cap);
      is_used[s[st].num] -= 1;
      if (is_used[s[st].num] == 0) tot -= 1;
      st += 1;
    }
  }
  cout << mn;
  return 0;
}