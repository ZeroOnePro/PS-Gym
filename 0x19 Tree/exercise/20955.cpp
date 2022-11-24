#include <bits/stdc++.h>

using namespace std;

const int range = 1e6 + 5;

int n, m, ans;
vector<int> adj[range];
bool vis[range];

void dfs(int cur, int par) {
  for (int nxt : adj[cur]) {
    if (nxt == par) continue;
    // cycle detection
    if (vis[nxt]) {
      ans += 1;
      continue;
    }
    vis[nxt] = true;
    dfs(nxt, cur);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  int cc = -1;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      vis[i] = true;
      dfs(i, -1);
      cc += 1;
    }
  }
  ans /= 2;
  ans += cc;
  cout << ans;
  return 0;
}