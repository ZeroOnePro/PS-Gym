#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

// 다익스트라
const int INF = 0x3f3f3f3f;
const int range = 55;

vector<pi2> adj[range];
int dist[range];

void dijkstra() {
  fill(dist + 1, dist + range, INF);
  priority_queue<pi2, vector<pi2>, greater<pi2>> pq;
  pq.push({0, 1});
  dist[1] = 0;
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[cur] != d) continue;
    for (auto [cost, nxt] : adj[cur]) {
      int new_dist = dist[cur] + cost;
      if (dist[nxt] > new_dist) {
        dist[nxt] = new_dist;
        pq.push({new_dist, nxt});
      }
    }
  }
}

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;
  for (vector<int> r : road) {
    int from = r[0], to = r[1], cost = r[2];
    adj[from].push_back({cost, to});
    adj[to].push_back({cost, from});
  }
  dijkstra();
  for (int i = 1; i <= N; ++i)
    if (dist[i] <= K) answer += 1;
  return answer;
}