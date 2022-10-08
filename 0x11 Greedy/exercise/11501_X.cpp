#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, cur = 0;
    long long profit = 0, ans = 0;
    long long stock[1'000'005];
    deque<int> mxs;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> stock[i];
    long long mx = stock[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      if (mx <= stock[i]) {
        mxs.push_front(i);
        mx = stock[i];
      }
    }
    for (auto m : mxs) {
      for (int i = cur; i < m; ++i) profit += stock[i];
      ans += ((m - cur) * stock[m] - profit);
      cur = m + 1;
      profit = 0;
    }
    cout << ans << '\n';
  }
  return 0;
}