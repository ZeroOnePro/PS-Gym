#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s;
  cin >> n >> s;
  int seq[n];
  for (int i = 0; i < n; ++i) cin >> seq[i];
  int en = 0, st = 0, min_len = INT_MAX, sub_sum = seq[0];
  for (st = 0; st < n; ++st) {
    while (en < n and sub_sum < s) {
      en += 1;
      if (en != n) sub_sum += seq[en];
    }
    if (en == n) break;
    min_len = min(min_len, en - st + 1);
    sub_sum -= seq[st];
  }
  cout << (min_len == INT_MAX or en == 0 ? 0 : min_len);
  return 0;
}