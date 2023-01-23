#include <bits/stdc++.h>

using namespace std;

#define cost first
#define node second

vector<pair<int, int>> adj[20005];

const int INF = 0x3f3f3f3f;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e, start;
  cin >> v >> e >> start;
  for (int i = 0; i < e; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].push_back({cost, to});
  }

  int dist[v + 1];
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  fill(dist + 1, dist + v + 1, INF);
  pq.push({0, start});
  dist[start] = 0;
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (dist[cur.node] != cur.cost) continue;
    for (auto edge : adj[cur.node]) {
      if (dist[edge.node] > dist[cur.node] + edge.cost) {
        dist[edge.node] = dist[cur.node] + edge.cost;
        pq.push({dist[edge.node], edge.node});
      }
    }
  }
  for (int i = 1; i <= v; ++i) {
    if (dist[i] == INF)
      cout << "INF";
    else
      cout << dist[i];
    cout << '\n';
  }
  return 0;
}