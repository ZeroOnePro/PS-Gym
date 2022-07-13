#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int min_diff = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int target = lower_bound(a, a + n, a[i] + m) - a;
    if (target >= n) continue;
    min_diff = min(min_diff, a[target] - a[i]);
  }
  cout << min_diff << '\n';
  return 0;
}