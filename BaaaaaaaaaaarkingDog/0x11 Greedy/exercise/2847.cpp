#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, cnt = 0, ans = 0;
  int s[105];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = n - 2; i >= 0; --i) {
    if (s[i + 1] <= s[i]) {
      cnt = (s[i] - s[i + 1] + 1);
      s[i] -= cnt;
      ans += cnt;
    }
  }
  cout << ans;
  return 0;
}