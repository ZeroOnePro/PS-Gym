#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, ans = 0;
  cin >> n >> k;
  if (n <= k) {
    cout << 0;
    return 0;
  }
  while (true) {
    int group = 0;
    int tmp = n;
    while (tmp > 0) {
      if (tmp & 1) group += 1;
      tmp >>= 1;
    }
    if (group <= k) break;
    n += 1;
    ans += 1;
  }
  cout << ans;
  return 0;
}