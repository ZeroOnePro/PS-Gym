#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int en = 0;
  int min_diff = INT_MAX;
  sort(a, a + n);
  for (int st = 0; st < n; ++st) {
    while (en < n and a[en] - a[st] < m) en += 1;
    if (en == n) break;
    min_diff = min(min_diff, a[en] - a[st]);
  }
  cout << min_diff << '\n';
  return 0;
}