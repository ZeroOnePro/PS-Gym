#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

int n, m;
vector<int> adj[range];
int deg[range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<int> q;
  vector<int> order;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int s, prev, cur;
    cin >> s;
    for (int j = 0; j < s; ++j) {
      cin >> cur;
      if (j >= 1) {
        adj[prev].push_back(cur);
        deg[cur] += 1;
      }
      prev = cur;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    order.push_back(cur);
    for (int nxt : adj[cur]) {
      deg[nxt] -= 1;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
  if (order.size() != n)
    cout << 0 << '\n';
  else {
    for (int s : order) cout << s << '\n';
  }
  return 0;
}