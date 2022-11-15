#include <bits/stdc++.h>

using namespace std;

vector<int> adj[505];
int dist[505];
int cnt;

void bfs(int st) {
  queue<int> q;
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      dist[nxt] = dist[cur] + 1;
      if (dist[nxt] <= 2) cnt += 1;
      q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e;
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  fill(dist, dist + 505, -1);
  bfs(1);
  cout << cnt;
  return 0;
}