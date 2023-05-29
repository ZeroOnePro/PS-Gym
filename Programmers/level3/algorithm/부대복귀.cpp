#include <bits/stdc++.h>

using namespace std;

// 다익스트라

typedef pair<int, int> pi2;

const int INF = 0x3f3f3f3f;
const int range = 100'005;

vector<pi2> adj[range];
int dist[range];

void dijkstra(int st) {
  priority_queue<pi2, vector<pi2>, greater<pi2>> pq;
  fill(dist + 1, dist + range, INF);
  pq.push({0, st});
  dist[st] = 0;
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if (dist[cur] != d) continue;
    for (auto [cost, nxt] : adj[cur]) {
      int ndist = d + cost;
      if (dist[nxt] > ndist) {
        dist[nxt] = ndist;
        pq.push({ndist, nxt});
      }
    }
  }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources,
                     int destination) {
  vector<int> answer;
  for (vector<int> r : roads) {
    int from = r[0], to = r[1];
    adj[from].push_back({1, to});
    adj[to].push_back({1, from});
  }
  dijkstra(destination);
  for (int s : sources) answer.push_back(dist[s] == INF ? -1 : dist[s]);
  return answer;
}