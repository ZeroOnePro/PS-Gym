#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
bool vis[105];
int cnt = 0;

void dfs(int cur) {
  for (auto nxt : adj[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    cnt += 1;
    dfs(nxt);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e;
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  vis[1] = true;
  dfs(1);
  cout << cnt;
  return 0;
}