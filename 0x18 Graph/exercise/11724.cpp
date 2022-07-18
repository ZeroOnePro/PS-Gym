#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    visited[cur] = true;
    for (int nxt : adj[cur]) {
      if (visited[nxt]) continue;
      q.push(nxt);
      visited[nxt] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e;
  cin >> v >> e;
  while (e--) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  int cc = 0;
  for (int i = 1; i <= v; ++i) {
    if (visited[i]) continue;
    bfs(i);
    cc += 1;
  }
  cout << cc << '\n';
  return 0;
}