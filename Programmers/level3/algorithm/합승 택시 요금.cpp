#include <bits/stdc++.h>

using namespace std;

// 다익스트라
// s, a, b에서 시작하는 다익스트라 돌린다

const int INF = 0x3f3f3f3f;
const int range = 205;

typedef long long ll;
typedef pair<ll, int> pli;

vector<pli> adj[range];
ll dist[3][range];

void dijkstra(int idx, int st) {
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  fill(dist[idx], dist[idx] + range, INF);
  dist[idx][st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[idx][cur] != d) continue;
    for (auto [cost, nxt] : adj[cur]) {
      ll new_dist = cost + dist[idx][cur];
      if (dist[idx][nxt] > new_dist) {
        dist[idx][nxt] = new_dist;
        pq.push({new_dist, nxt});
      }
    }
  }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  int answer = 0;
  for (auto edge : fares) {
    int from = edge[0], to = edge[1];
    ll cost = edge[2];
    adj[from].push_back({cost, to});
    adj[to].push_back({cost, from});
  }
  dijkstra(0, s);
  dijkstra(1, a);
  dijkstra(2, b);
  ll mn = LONG_LONG_MAX;
  for (int i = 1; i <= n; ++i)
    mn = min(
        {dist[0][i] + dist[1][i] + dist[2][i], dist[0][a] + dist[0][b], mn});
  answer = mn;
  return answer;
}