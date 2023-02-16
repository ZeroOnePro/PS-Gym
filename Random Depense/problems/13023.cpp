#include <bits/stdc++.h>

using namespace std;

const int range = 2005;

int n, m;
bool res;

vector<int> adj[range];
vector<bool> vis(range);

void dfs(int cur, int depth) {
  if (depth == 4) {
    res = true;
    return;
  }
  for (int nxt : adj[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    dfs(nxt, depth + 1);
    vis[nxt] = false;
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
  for (int i = 0; i < n; ++i) {
    fill(vis.begin(), vis.begin() + n, false);
    vis[i] = true;
    dfs(i, 0);
    if (res) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}