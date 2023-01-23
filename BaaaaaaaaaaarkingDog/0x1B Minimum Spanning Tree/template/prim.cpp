#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  tuple<int, int, int> edges[] = {
      {4, 1, 2}, {3, 1, 3}, {3, 1, 4}, {3, 3, 4},
      {6, 4, 5}, {5, 3, 5}, {8, 2, 5},
  };
  int v = 5;
  // (비용, 정점)
  vector<pair<int, int>> adj[v + 1];
  for (auto edge : edges) {
    int cost, from, to;
    tie(cost, from, to) = edge;
    adj[from].push_back({cost, to});
    adj[to].push_back({cost, from});
  }
  // (비용, 정점 1, 정점 2)
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  vector<bool> mst_nodes(v + 1, false);
  int start = 1;
  mst_nodes[start] = true;
  for (auto edge : adj[start]) {
    pq.push({edge.first, start, edge.second});
  }
  int mst_edge = 0, min_cost = 0;
  while (mst_edge < v - 1) {
    int cost, cur, nxt;
    tie(cost, cur, nxt) = pq.top();
    pq.pop();
    if (mst_nodes[nxt]) continue;
    mst_nodes[nxt] = true;
    min_cost += cost;
    mst_edge += 1;
    for (auto edge : adj[nxt]) {
      if (!mst_nodes[edge.second]) pq.push({edge.first, nxt, edge.second});
    }
  }
  cout << min_cost << '\n';
  return 0;
}