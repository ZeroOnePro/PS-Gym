#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

typedef long long ll;

const int range = 805;
const int INF = 0x3f3f3f3f;

int n, e, u, v;
vector<pii> adj[range];
ll dist[range][range];

void dijkstra(int st, priority_queue<pii, vector<pii>, greater<pii>>& pq) {
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[st][cur] != d) continue;
    for (auto [cost, nxt] : adj[cur]) {
      ll new_dist = dist[st][cur] + cost;
      if (dist[st][nxt] > new_dist) {
        dist[st][nxt] = new_dist;
        pq.push({new_dist, nxt});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  cin >> n >> e;
  for (int i = 0; i < e; ++i) {
    int st, en, cost;
    cin >> st >> en >> cost;
    adj[st].push_back({cost, en});
    adj[en].push_back({cost, st});
  }
  cin >> u >> v;
  for (int i = 1; i <= n; ++i) {
    fill(dist[i] + 1, dist[i] + n + 1, INF);
    dist[i][i] = 0;
  }
  for (int st : {1, u, v}) {
    pq.push({0, st});
    dijkstra(st, pq);
  }
  // 1 -> v -> u -> N
  ll ans1 = dist[1][v] + dist[v][u] + dist[u][n];
  // 1 -> u -> v -> N
  ll ans2 = dist[1][u] + dist[u][v] + dist[v][n];
  ll ans = min(ans1, ans2);
  if (ans >= INF)
    cout << -1;
  else
    cout << ans;
  return 0;
}