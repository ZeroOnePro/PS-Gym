#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

vector<pair<int, int>> adj[range];
int dist[range];

int bfs(int st, int en) {
  queue<int> q;
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto [nxt, weight] : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      if (nxt == en) return dist[cur] + weight;
      dist[nxt] = dist[cur] + weight;
      q.push(nxt);
    }
  }
  return dist[en];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n - 1; ++i) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({to, w});
    adj[to].push_back({from, w});
  }
  while (m--) {
    int st, en;
    cin >> st >> en;
    fill(dist + 1, dist + 1 + n, -1);
    cout << bfs(st, en) << '\n';
  }
  return 0;
}