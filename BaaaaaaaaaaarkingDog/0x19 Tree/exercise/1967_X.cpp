#include <bits/stdc++.h>

using namespace std;

const int range = 10'005;

int n, mx_far, mx_dist;
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
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({to, w});
    adj[to].push_back({from, w});
  }
  dfs(1, 0);
  fill(vis, vis + n + 1, false);
  mx_dist = 0;
  dfs(mx_far, 0);
  cout << mx_dist;
  return 0;
}