#include <bits/stdc++.h>

using namespace std;

#define cost first
#define node second

vector<pair<int, int>> adj[1005];

const int INF = 10 + 1e9;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e, st, en;
  cin >> v >> e;
  while (e--) {
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].push_back({cost, to});
  }
  cin >> st >> en;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  int dist[v + 1];
  int pre[v + 1];
  fill(dist + 1, dist + v + 1, INF);
  dist[st] = 0;
  pre[st] = 0;
  pre[0] = -1;
  pq.push({0, st});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (dist[cur.node] != cur.cost) continue;
    for (auto edge : adj[cur.node]) {
      if (dist[edge.node] > dist[cur.node] + edge.cost) {
        dist[edge.node] = dist[cur.node] + edge.cost;
        pre[edge.node] = cur.node;
        pq.push({dist[edge.node], edge.node});
      }
    }
  }
  cout << dist[en] << '\n';
  stack<int> path;
  int cur = en;
  while (pre[cur] != -1) {
    path.push(cur);
    cur = pre[cur];
  }

  cout << (int)path.size() << '\n';
  while (!path.empty()) {
    cout << path.top() << ' ';
    path.pop();
  }
  return 0;
}