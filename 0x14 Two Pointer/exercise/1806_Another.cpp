#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s;
  cin >> n >> s;
  int seq[n], acc[n];
  for (int i = 0; i < n; ++i) cin >> seq[i];
  acc[0] = seq[0];
  for (int i = 1; i < n; ++i) acc[i] = acc[i - 1] + seq[i];
  int bound_len = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int tmp_len =
        lower_bound(acc, acc + n, s + (i == 0 ? 0 : acc[i - 1])) - acc;
    if (tmp_len >= n) continue;
    bound_len = min(bound_len, tmp_len - i + 1);
  }
  cout << (bound_len == INT_MAX ? 0 : bound_len);
  return 0;
}