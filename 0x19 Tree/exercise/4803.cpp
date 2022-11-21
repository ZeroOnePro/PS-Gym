#include <bits/stdc++.h>

using namespace std;

const int range = 505;

int n, m, cs = 1;
vector<int> adj[range];
bool vis[range];
bool is_tree;

void dfs(int cur, int par) {
  for (int nxt : adj[cur]) {
    if (nxt == par) continue;
    if (vis[nxt]) {
      is_tree = false;
      return;
    }
    vis[nxt] = true;
    dfs(nxt, cur);
  }
}

void init() {
  fill(vis + 1, vis + n + 1, false);
  for (int i = 1; i <= n; ++i) adj[i].clear();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    int cnt = 0;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    for (int i = 0; i < m; ++i) {
      int from, to;
      cin >> from >> to;
      adj[from].push_back(to);
      adj[to].push_back(from);
    }
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      vis[i] = true;
      is_tree = true;
      dfs(i, -1);
      if (is_tree) cnt += 1;
    }
    cout << "Case " << cs++ << ": ";
    if (cnt == 0)
      cout << "No trees.\n";
    else if (cnt == 1)
      cout << "There is one tree.\n";
    else
      cout << "A forest of " + to_string(cnt) + " trees.\n";
    init();
  }
  return 0;
}