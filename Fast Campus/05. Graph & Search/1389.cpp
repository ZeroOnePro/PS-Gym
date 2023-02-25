#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int v, e;
set<int> adj[105];
int dist[105];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

void bfs(int st) {
  queue<int> q;
  q.push(st);
  fill(dist + 1, dist + v + 1, -1);
  dist[st] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  int sum_dist = 0;
  for (int i = 1; i <= v; ++i) sum_dist += dist[i];
  pq.push({sum_dist, st});
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].insert(to);
    adj[to].insert(from);
  }
  for (int i = 1; i <= v; ++i) bfs(i);
  cout << pq.top().y;
  return 0;
}