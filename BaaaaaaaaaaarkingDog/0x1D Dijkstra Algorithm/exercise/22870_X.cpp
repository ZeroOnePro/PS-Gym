#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pil pair<int, ll>
#define tlii tuple<ll, int, int>

const int range = 200'005;
const ll INF = 0x7f7f7f7f7f7f;

int n, m, s, e;

vector<pil> adj[range];
ll dist_s[range], dist_e[range];
int vis[range];

void dijkstra(int st, ll dist[]) {
  priority_queue<pil, vector<pil>, greater<>> pq;
  fill(dist, dist + n + 1, INF);
  dist[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [cur_dist, cur] = pq.top();
    pq.pop();
    if (dist[cur] != cur_dist) continue;
    for (auto [nxt, cost] : adj[cur]) {
      if (vis[nxt]) continue;
      ll nxt_dist = dist[cur] + cost;
      if (nxt_dist < dist[nxt]) {
        dist[nxt] = nxt_dist;
        pq.push({nxt_dist, nxt});
      }
    }
  }
}

void mark_vis_node() {
  int prev = s;
  int cur = s;
  while (cur != e) {
    int mn = INT_MAX;
    for (auto [nxt, cost] : adj[cur]) {
      // nxt가 최단 경로에 포함된 정점인지 확인
      if (nxt == prev) continue;
      // meet in the middle
      if (dist_s[cur] + cost + dist_e[nxt] == dist_s[e]) mn = min(nxt, mn);
    }
    prev = cur;
    cur = mn;
    if (cur != e) vis[cur] = true;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({v, cost});
    adj[v].push_back({u, cost});
  }
  cin >> s >> e;
  dijkstra(s, dist_s);
  dijkstra(e, dist_e);
  mark_vis_node();
  dijkstra(e, dist_e);
  cout << dist_s[e] + dist_e[s];
  return 0;
}