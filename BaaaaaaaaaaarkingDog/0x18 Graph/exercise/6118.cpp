#include <bits/stdc++.h>

using namespace std;

const int range = 20'005;

int v, e;
vector<int> adj[range];
int dist[range];
int mx;

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
      mx = max(dist[nxt], mx);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  bfs(1);
  int cnt = 0, hide = 0;
  for (int i = 1; i <= v; ++i)
    if (mx == dist[i]) {
      cnt += 1;
      if (hide == 0) hide = i;
    }
  cout << hide << ' ' << mx << ' ' << cnt;
  return 0;
}