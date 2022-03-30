#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;

int dist[1000002];

void bfs(queue<int>& q) {
  while (!q.empty()) {
    if (dist[g] != -1) {
      cout << dist[g];
      return;
    }
    int cur = q.front();
    q.pop();
    for (int nxt : {cur - d, cur + u}) {
      if (nxt <= 0 || nxt > f) continue;
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
  cout << "use the stairs";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<int> q;
  cin >> f >> s >> g >> u >> d;
  fill(dist, dist + f + 1, -1);
  dist[s] = 0;
  q.push(s);
  bfs(q);
  return 0;
}