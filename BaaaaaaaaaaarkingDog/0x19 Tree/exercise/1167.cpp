#include <bits/stdc++.h>

using namespace std;

const int range = 100'005;

int v, mx_far, mx_dist;
vector<pair<int, int>> adj[range];
bool vis[range];

void dfs(int cur, int dist) {
  vis[cur] = true;
  for (auto [nxt, w] : adj[cur]) {
    if (vis[nxt]) continue;
    if (mx_dist < dist + w) {
      mx_dist = dist + w;
      mx_far = nxt;
    }
    dfs(nxt, dist + w);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> v;
  for (int i = 0; i < v; ++i) {
    int from, to, w;
    cin >> from;
    while (true) {
      int to, w;
      cin >> to;
      if (to == -1) break;
      cin >> w;
      adj[from].push_back({to, w});
      adj[to].push_back({from, w});
    }
  }
  dfs(1, 0);
  fill(vis, vis + v + 1, false);
  mx_dist = 0;
  dfs(mx_far, 0);
  cout << mx_dist;
  return 0;
}