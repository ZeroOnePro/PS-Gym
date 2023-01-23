#include <bits/stdc++.h>

using namespace std;

#define cost first
#define node second

// (비용, 정점 1, 정점 2)
tuple<int, int, int> edge[] = {
    {3, 1, 2}, {2, 1, 3}, {5, 1, 4}, {2, 2, 3},
    {2, 3, 4}, {8, 2, 5}, {6, 4, 5}, {1, 5, 6},
};

// (비용, 정점)
vector<pair<int, int>> adj[7];

const int INF = 0x3f3f3f3f;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v = 6, start = 1;
  for (auto e : edge) {
    int cost, from, to;
    tie(cost, from, to) = e;
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
    // 우선순위 큐에는 어떤 간선이 들어갈 지 모르기 때문에, 최단 경로에
    // 포함되지 않는 간선은 걸러줄 필요가 있다 우선순위 큐에 집어 넣을 때마다
    // 최단 거리 테이블이 갱신되기에 최단 거리 테이블에 있는 값이 현재까지의
    // 최단거리이고, 우선순위 큐에 집어넣을 때 최단 거리 테이블도 갱신되므로
    // 최단 경로에 포함되는 간선이라면 우선 순위 큐에서 나오는 가중치와 최단
    // 경로 테이블에 있는 가중치가 같아야함
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