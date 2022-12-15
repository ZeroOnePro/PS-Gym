#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pli pair<ll, int>

const int range = 100'005;
const ll INF = 0x7f7f7f7f7f;

int n, m;

vector<pli> adj[range];
ll dist[range];

void dijkstra() {
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  fill(dist, dist + n + 1, INF);
  dist[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [cur_time, cur] = pq.top();
    pq.pop();
    if (dist[cur] != cur_time) continue;
    for (auto [nxt_time, nxt] : adj[cur]) {
      // 다음 이동할 횡단보도 신호의 시작 시간이
      // 현재 시간보다 이전의 시간이라면
      // 다음 신호시작 시간으로 교체하여
      // 딜레이 구현
      if (nxt_time < cur_time) {
        ll diff = cur_time - nxt_time;
        ll delta = diff / m;
        delta += (diff % m != 0);
        nxt_time += m * delta;
      }
      // 횡단보도 건너기(1분)
      nxt_time += 1;
      if (dist[nxt] > nxt_time) {
        dist[nxt] = nxt_time;
        pq.push({nxt_time, nxt});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({i, v});
    adj[v].push_back({i, u});
  }
  dijkstra();
  cout << dist[n];
  return 0;
}