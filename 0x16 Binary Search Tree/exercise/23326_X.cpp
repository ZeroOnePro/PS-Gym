#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, cur = 1;
  cin >> n >> q;
  set<int> sights;
  for (int i = 1; i <= n; ++i) {
    int s;
    cin >> s;
    if (s) sights.insert(i);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i;
      cin >> i;
      if (sights.find(i) != sights.end())
        sights.erase(i);
      else
        sights.insert(i);
    } else if (op == 2) {
      int x;
      cin >> x;
      cur = (cur + x - 1) % n + 1;
    } else {
      if (!sights.empty()) {
        auto it = sights.lower_bound(cur);
        if (it != sights.end())
          cout << *it - cur << '\n';
        else
          cout << n - cur + *sights.begin() << '\n';
      } else
        cout << -1 << '\n';
    }
  }
  return 0;
}