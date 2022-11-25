#include <bits/stdc++.h>

using namespace std;

const int range = 1e6 + 5;

int n, m;
vector<int> adj[range];
bool vis[range];
int score[range];

void bfs() {
  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      score[nxt] += score[cur];
      vis[nxt] = true;
      q.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int par;
    cin >> par;
    if (i >= 2) {
      adj[par].push_back(i);
      adj[i].push_back(par);
    }
  }
  for (int i = 0; i < m; ++i) {
    int en, w;
    cin >> en >> w;
    score[en] += w;
  }
  bfs();
  for (int i = 1; i <= n; ++i) cout << score[i] << ' ';
  return 0;
}