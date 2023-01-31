#include <bits/stdc++.h>

using namespace std;

#define pi2 pair<int, int>

const int range = 1e5 + 5;

int n, m, s, e;

vector<pi2> adj[range];
bool vis[range];

// x이하의 가중치를 갖는 간선들로 구성된 경로로
// 시작점에서 도착점으로 도달이 가능한가?
bool bfs(int x) {
  queue<int> q;
  fill(vis, vis + range, false);
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto [nxt, w] : adj[cur]) {
      if (vis[nxt] || w <= x) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
  // false면 도달 불가
  return vis[e];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> s >> e;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int st = 0, en = 1e6;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (bfs(mid))
      st = mid + 1;
    else
      en = mid - 1;
  }
  cout << st;
  return 0;
}