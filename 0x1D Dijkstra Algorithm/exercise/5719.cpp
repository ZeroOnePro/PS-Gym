#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int range = 505;
const int INF = 0x3f3f3f3f;

int n, m, s, d;

int adj[range][range];
vector<int> p[range];
int dist[range];
bool vis[range];

void init() {
  for (int i = 0; i < n; ++i) {
    p[i].clear();
    fill(adj[i], adj[i] + n, INF);
    adj[i][i] = 0;
  }
}

void dijkstra() {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  fill(dist, dist + n, INF);
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [cur_dist, cur] = pq.top();
    pq.pop();
    if (dist[cur] != cur_dist) continue;
    for (int nxt = 0; nxt < n; ++nxt) {
      if (nxt == cur) continue;
      int new_dist = dist[cur] + adj[cur][nxt];
      if (dist[nxt] > new_dist) {
        dist[nxt] = new_dist;
        pq.push({new_dist, nxt});
        p[nxt].clear();
        p[nxt].push_back(cur);
      }
      // 최단 경로가 여러개일 수 있음
      else if (dist[nxt] == new_dist)
        p[nxt].push_back(cur);
    }
  }
}

void bfs() {
  queue<int> q;
  fill(vis, vis + n, false);
  q.push(d);
  vis[d] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int nxt : p[cur]) {
      // 찾은 최단 경로 없애기
      adj[nxt][cur] = INF;
      if (vis[nxt]) continue;
      vis[nxt] = true;
      q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    cin >> s >> d;
    init();
    for (int i = 0; i < m; ++i) {
      int u, v, p;
      cin >> u >> v >> p;
      adj[u][v] = p;
    }
    dijkstra();
    bfs();
    dijkstra();
    if (dist[d] >= INF)
      cout << -1 << '\n';
    else
      cout << dist[d] << '\n';
  }
  return 0;
}