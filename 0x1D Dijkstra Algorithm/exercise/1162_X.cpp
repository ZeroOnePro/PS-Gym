#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pli pair<ll, int>
#define tlii tuple<ll, int, int>

const int range = 10'005;
const ll INF = 0x7f7f7f7f7f7f;

int n, m, k;

vector<pli> adj[range];
// 1차원은 정점, 2차원은 포장을 몇 번 했는지 저장
ll dist[range][25];

void dijkstra() {
  // (가중치, 정점, 포장 횟수)
  priority_queue<tlii, vector<tlii>, greater<tlii>> pq;
  for (int i = 1; i <= n; ++i) fill(dist[i], dist[i] + 25, INF);
  pq.push({0, 1, 0});
  dist[1][0] = 0;
  while (!pq.empty()) {
    auto [d, cur, pave] = pq.top();
    pq.pop();
    if (dist[cur][pave] != d) continue;
    for (auto [cost, nxt] : adj[cur]) {
      // 포장이 가능한 경우
      if (pave < k && dist[nxt][pave + 1] > d) {
        dist[nxt][pave + 1] = d;
        pq.push({d, nxt, pave + 1});
      }
      if (dist[nxt][pave] > dist[cur][pave] + cost) {
        dist[nxt][pave] = dist[cur][pave] + cost;
        pq.push({dist[nxt][pave], nxt, pave});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }
  dijkstra();
  ll ans = *min_element(dist[n], dist[n] + k + 1);
  cout << ans;
  return 0;
}