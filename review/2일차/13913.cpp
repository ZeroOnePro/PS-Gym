#include <bits/stdc++.h>

using namespace std;

const int range = 100'001;

int n, k;
int dist[range];
int path[range];

void bfs() {
  queue<int> q;
  fill(dist, dist + range, -1);
  q.push(n);
  dist[n] = 0;
  path[n] = -1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : {cur - 1, cur + 1, cur * 2}) {
      if (nxt < 0 || nxt >= range) continue;
      if (dist[nxt] >= 0) continue;
      if (nxt == k) {
        dist[nxt] = dist[cur] + 1;
        path[nxt] = cur;
        return;
      }
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
  bfs();
  cout << dist[k] << '\n';
  int cur = k;
  stack<int> s;
  while (cur != -1) {
    s.push(cur);
    cur = path[cur];
  }
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  return 0;
}