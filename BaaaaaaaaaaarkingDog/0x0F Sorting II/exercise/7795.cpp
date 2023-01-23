#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
      int in;
      cin >> in;
      a.push_back(in);
    }
    for (int i = 0; i < m; ++i) {
      int in;
      cin >> in;
      b.push_back(in);
    }
    sort(a.begin(), a.end());
    for (int i : b) {
      int li = 0;
      while (li < n && i >= a[li]) li += 1;
      ans += a.size() - li;
    }
    cout << ans << '\n';
  }
  return 0;
}