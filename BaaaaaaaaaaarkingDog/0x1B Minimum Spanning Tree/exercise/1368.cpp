#include <bits/stdc++.h>

using namespace std;

// (비용, 정점)
vector<pair<int, int>> adj[305];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v;
  cin >> v;
  for (int i = 1; i <= v; ++i) {
    int p;
    cin >> p;
    adj[i].push_back({p, v + 1});
    adj[v + 1].push_back({p, i});
  }
  for (int i = 1; i <= v; ++i) {
    for (int j = 1; j <= v; ++j) {
      int p;
      cin >> p;
      if (i == j) continue;
      adj[i].push_back({p, j});
    }
  }
  // (비용, 정점)
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  v += 1;
  vector<bool> mst_nodes(v + 1, false);
  for (auto edge : adj[v]) {
    pq.push({edge.first, edge.second});
  }
  mst_nodes[v] = true;
  int min_cost = 0, mst_edge = 0;
  while (mst_edge < v - 1) {
    auto cur = pq.top();
    pq.pop();
    int cost = cur.first, nxt = cur.second;
    if (mst_nodes[nxt]) continue;
    mst_nodes[nxt] = true;
    mst_edge += 1;
    min_cost += cost;
    for (auto edge : adj[nxt])
      if (!mst_nodes[edge.second]) pq.push({edge.first, edge.second});
  }
  cout << min_cost;
  return 0;
}