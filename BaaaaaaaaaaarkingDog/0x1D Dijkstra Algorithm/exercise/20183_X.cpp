#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pli pair<ll, int>
#define tlii tuple<ll, int, int>

const int range = 100'005;
const ll INF = 0x7f7f7f7f7f7f;

int n, m, a, b;
ll c;

vector<pli> adj[range];
ll dist[range];
vector<ll> w;

bool dijkstra(ll x) {
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  fill(dist, dist + n + 1, INF);
  dist[a] = 0;
  pq.push({0, a});
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[cur] != d) continue;
    for (auto [cost, nxt] : adj[cur]) {
      ll new_dist = cost + dist[cur];
      if (cost <= x && dist[nxt] > new_dist) {
        dist[nxt] = new_dist;
        pq.push({new_dist, nxt});
      }
    }
  }
  return dist[b] <= c;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> a >> b >> c;
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
    w.push_back(cost);
  }
  sort(w.begin(), w.end());
  w.erase(unique(w.begin(), w.end()), w.end());
  int st = 0, en = w.size() - 1;
  ll ans = -1;
  while (st <= en) {
    int mid = (st + en) / 2;
    ll target = w[mid];
    if (dijkstra(target)) {
      en = mid - 1;
      ans = target;
    } else
      st = mid + 1;
  }
  cout << ans;
  return 0;
}