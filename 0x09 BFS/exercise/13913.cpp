#include <bits/stdc++.h>

using namespace std;

const int range = 1e6 * 2 + 1;

int n, k;
int dist[range];
int path[range];

void bfs(void) {
  queue<int> q;
  q.push(n);
  dist[n] = 0;
  while (dist[k] == -1) {
    auto cur = q.front();
    q.pop();
    for (int nxt : {cur - 1, cur + 1, cur * 2}) {
      if (nxt < 0 || nxt > 1e6 + 1) continue;
      if (dist[nxt] >= 0) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
      path[nxt] = cur;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  fill(dist, dist + range, -1);
  bfs();
  cout << dist[k] << '\n';
  stack<int> s;
  int cur = k;
  while (cur != n) {
    s.push(cur);
    cur = path[cur];
  }
  s.push(n);
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  return 0;
}