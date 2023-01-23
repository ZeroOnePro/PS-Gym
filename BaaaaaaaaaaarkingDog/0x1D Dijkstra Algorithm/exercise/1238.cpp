#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int range = 1'005;
const int INF = 0x3f3f3f3f;

int n, m, target;
// (비용, 정점)
vector<pii> adj[range];
int dist[range][range];

// To do
// 다익스트라 구현하기
// 1. 모든 정점에 대해서 최단거리 테이블을 갱신한다
// 2. 최단 거리 테이블의 값과 큐에 넣은 값이 다르면 skip
// 3. 큐에서 꺼낸 값이 최단거리 테이블에 있는 값과 같으면 이 정점을 통해
// 최단경로가 변경되는 정점이 있는지 본다
void dijkstra(int st, priority_queue<pii, vector<pii>, greater<pii>>& pq) {
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[st][cur] != d) continue;
    for (auto [cost, nxt] : adj[cur]) {
      int new_dist = dist[st][cur] + cost;
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
  cin >> n >> m >> target;
  for (int i = 0; i < m; ++i) {
    int st, en, cost;
    cin >> st >> en >> cost;
    adj[st].push_back({cost, en});
  }
  for (int i = 1; i <= n; ++i) {
    fill(dist[i] + 1, dist[i] + n + 1, INF);
    dist[i][i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    pq.push({0, i});
    dijkstra(i, pq);
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) mx = max(mx, dist[i][target] + dist[target][i]);
  cout << mx;
  return 0;
}