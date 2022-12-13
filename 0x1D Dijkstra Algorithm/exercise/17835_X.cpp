#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pli pair<ll, int>

const int range = 100'005;
const ll INF = 0x7f7f7f7f7f7f;

int n, m, k;

ll dist[range];
vector<pli> adj[range];

void dijkstra(priority_queue<pli, vector<pli>, greater<pli>>& pq) {
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[cur] != d) continue;
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
  cin >> n >> m >> k;
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  fill(dist, dist + n + 1, INF);
  for (int i = 0; i < m; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[v].push_back({cost, u});
  }
  for (int i = 0; i < k; ++i) {
    int st;
    cin >> st;
    dist[st] = 0;
    pq.push({0, st});
  }
  dijkstra(pq);
  int city = max_element(dist + 1, dist + n + 1) - dist;
  cout << city << '\n' << dist[city];
  return 0;
}