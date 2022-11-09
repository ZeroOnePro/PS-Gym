#include <bits/stdc++.h>

using namespace std;

map<string, int> op;
string cmds[] = {"recommend", "recommend2", "recommend3", "add", "solved"};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  map<int, multiset<pair<int, int>>> g2p;
  map<int, set<int>> l2p;
  map<int, pair<int, int>> p2gl;
  cin >> n;
  while (n--) {
    int p, l, g;
    cin >> p >> l >> g;
    p2gl[p] = {l, g};
    g2p[g].insert({l, p});
    l2p[l].insert(p);
  }
  cin >> m;
  for (int i = 0; i < 5; ++i) op.insert({cmds[i], i});
  while (m--) {
    string cmd;
    int p, l, g, x;
    cin >> cmd;
    switch (op[cmd]) {
      case 0:
        cin >> g >> x;
        if (x == 1)
          cout << prev(g2p[g].end())->second << '\n';
        else
          cout << g2p[g].begin()->second << '\n';
        break;
      case 1:
        cin >> x;
        if (x == 1) {
          auto [k, v] = *prev(l2p.end());
          cout << *prev(v.end()) << '\n';
        } else {
          auto [k, v] = *l2p.begin();
          cout << *v.begin() << '\n';
        }
        break;
      case 2:
        cin >> x >> l;
        if (x == 1) {
          auto lb = l2p.lower_bound(l);
          if (lb != l2p.end()) {
            auto [k, v] = *lb;
            cout << *v.begin() << '\n';
          } else
            cout << -1 << '\n';
        } else {
          auto lb = l2p.lower_bound(l);
          if (lb != l2p.end() && lb != l2p.begin()) {
            while (lb != l2p.begin() && lb->first >= l) lb = prev(lb);
            cout << *prev(lb->second.end()) << '\n';
          } else
            cout << -1 << '\n';
        }
        break;
      case 3:
        cin >> p >> l >> g;
        p2gl[p] = {l, g};
        l2p[l].insert(p);
        g2p[g].insert({l, p});
        break;
      case 4:
        cin >> p;
        tie(l, g) = p2gl[p];
        l2p[l].erase(p);
        if (l2p[l].empty()) l2p.erase(l);
        g2p[g].erase({l, p});
        if (g2p[g].empty()) g2p.erase(g);
        p2gl.erase(p);
        break;
    }
  }
  return 0;
}