#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int range = 1'005;
const int INF = 0x3f3f3f3f;

int n, m, k;

vector<pii> adj[range];
// kth_dist[i] => 1에서 i로 오는 경로 상위 k개 저장하는 최대힙
priority_queue<int> kth_dist[range];

void dijkstra() {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 1});
  kth_dist[1].push(0);
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    for (auto [cost, nxt] : adj[cur]) {
      int new_dist = d + cost;
      if (kth_dist[nxt].size() < k) {
        kth_dist[nxt].push(new_dist);
        pq.push({new_dist, nxt});
      } else if (kth_dist[nxt].top() > new_dist) {
        kth_dist[nxt].pop();
        kth_dist[nxt].push(new_dist);
        pq.push({new_dist, nxt});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }
  dijkstra();
  for (int i = 1; i <= n; ++i) {
    if (kth_dist[i].size() != k)
      cout << -1 << '\n';
    else
      cout << kth_dist[i].top() << '\n';
  }
  return 0;
}