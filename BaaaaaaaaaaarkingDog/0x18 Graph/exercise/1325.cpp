#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int range = 10'005;

int v, e;
vector<int> adj[range];
bool vis[range];
vector<pair<int, int>> d2v;

void bfs(int st) {
  int cnt = 1;
  queue<int> q;
  q.push(st);
  fill(vis + 1, vis + v + 1, false);
  vis[st] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      cnt += 1;
      vis[nxt] = true;
      q.push(nxt);
    }
  }
  d2v.push_back({cnt, st});
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int from, to;
    cin >> to >> from;
    adj[from].push_back(to);
  }
  for (int i = 1; i <= v; ++i) bfs(i);
  sort(d2v.begin(), d2v.end(), [&](pair<int, int> a, pair<int, int> b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x > b.x;
  });
  int mx = d2v[0].x;
  for (auto p : d2v) {
    if (p.x == mx)
      cout << p.y << ' ';
    else
      break;
  }
  return 0;
}