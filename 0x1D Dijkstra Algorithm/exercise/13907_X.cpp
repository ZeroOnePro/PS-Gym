#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int>

const int INF = 0x3f3f3f3f;
const int range = 1'005;

int n, m, k, s, d;

vector<pii> adj[range];
// 1차원 정점, 2차원은 거친 도시의 수
int dist[range][range];

void dijkstra() {
  // (거리, 정점, 거쳐온 도시 수)
  priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
  for (int i = 1; i <= n; ++i) fill(dist[i], dist[i] + n + 1, INF);
  pq.push({0, s, 0});
  dist[s][0] = 0;
  while (!pq.empty()) {
    auto [cur_dist, cur, cnt] = pq.top();
    pq.pop();
    if (dist[cur][cnt] != cur_dist) continue;
    for (auto [cost, nxt] : adj[cur]) {
      int new_dist = dist[cur][cnt] + cost;
      if (new_dist < dist[nxt][cnt + 1]) {
        dist[nxt][cnt + 1] = new_dist;
        pq.push({new_dist, nxt, cnt + 1});
      }
    }
  }
}

void clac_tax(int tax) {
  int mn = INF;
  for (int i = 1; i < n; ++i) {
    dist[d][i] += i * tax;
    // cout << "dist[" << d << "][" << i << "]: " << dist[d][i] << '\n';
    mn = min(dist[d][i], mn);
  }
  cout << mn << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k >> s >> d;
  for (int i = 0; i < m; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }
  dijkstra();
  clac_tax(0);
  for (int i = 0; i < k; ++i) {
    int t;
    cin >> t;
    clac_tax(t);
  }
  return 0;
}