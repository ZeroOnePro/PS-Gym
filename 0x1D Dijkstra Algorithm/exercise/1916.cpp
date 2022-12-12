#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pli pair<ll, int>

const int range = 1'005;
const int INF = 0x3f3f3f3f;

int n, m, s, e;

int adj_matrix[range][range];
vector<pli> adj[range];
ll dist[range];

void dijkstra(int st) {
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  dist[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    for (auto [cost, nxt] : adj[cur]) {
      ll new_dist = cost + dist[cur];
      if (dist[nxt] > new_dist) {
        dist[nxt] = new_dist;
        pq.push({new_dist, nxt});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  fill(dist, dist + n + 1, INF);
  for (int i = 0; i <= n; ++i) fill(adj_matrix[i], adj_matrix[i] + n + 1, INF);
  for (int i = 0; i < m; ++i) {
    int st, en, cost;
    cin >> st >> en >> cost;
    adj_matrix[st][en] = min(adj_matrix[st][en], cost);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) adj[i].push_back({adj_matrix[i][j], j});
  cin >> s >> e;
  dijkstra(s);
  cout << dist[e];
  return 0;
}