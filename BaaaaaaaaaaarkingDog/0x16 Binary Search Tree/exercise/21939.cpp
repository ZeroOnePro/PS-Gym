#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, p, l, m;
  map<int, int> p2l;
  map<int, set<int>> l2p;
  cin >> n;
  while (n--) {
    cin >> p >> l;
    p2l[p] = l;
    l2p[l].insert(p);
  }
  cin >> m;
  while (m--) {
    string cmd;
    cin >> cmd;
    if (cmd == "recommend") {
      int x, v;
      cin >> x;
      if (x == 1) {
        auto it = prev(l2p.end());
        v = *prev(it->second.end());
      } else {
        auto it = l2p.begin();
        v = *(it->second.begin());
      }
      cout << v << '\n';
    } else if (cmd == "solved") {
      cin >> p;
      tie(p, l) = *p2l.find(p);
      p2l.erase(p);
      l2p[l].erase(p);
      if (l2p[l].size() == 0) l2p.erase(l);
    } else {
      cin >> p >> l;
      p2l[p] = l;
      l2p[l].insert(p);
    }
  }
  return 0;
}