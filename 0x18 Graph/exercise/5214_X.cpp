#include <bits/stdc++.h>

using namespace std;

const int range = 1001005;

int n, k, m;
vector<int> adj[range];
int dist[range];

void bfs() {
  queue<int> q;
  fill(dist, dist + n + m + 1, -1);
  q.push(1);
  dist[1] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] >= 0) continue;
      dist[nxt] = nxt > n ? dist[cur] : dist[cur] + 1;
      q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= k; ++j) {
      int st;
      cin >> st;
      // v + i는 dummy node의 정점 번호
      adj[n + i].push_back(st);
      adj[st].push_back(n + i);
    }
  }
  bfs();
  cout << dist[n];
  return 0;
}