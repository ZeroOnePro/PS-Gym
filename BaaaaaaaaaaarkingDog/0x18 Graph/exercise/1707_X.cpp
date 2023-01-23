#include <bits/stdc++.h>

using namespace std;

const int range = 20'005;

int k, v, e;
vector<int> adj[range];
int color[range];

bool bfs(int st) {
  queue<int> q;
  q.push(st);
  color[st] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (color[nxt] != -1) {
        if (color[nxt] == color[cur])
          return false;
        else
          continue;
      }
      color[nxt] = 1 - color[cur];
      q.push(nxt);
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k;
  while (k--) {
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
      int from, to;
      cin >> from >> to;
      adj[from].push_back(to);
      adj[to].push_back(from);
    }
    bool is_bi = true;
    fill(color + 1, color + v + 1, -1);
    for (int i = 1; i <= v; ++i) {
      if (color[i] != -1) continue;
      is_bi = bfs(i);
      if (!is_bi) break;
    }
    cout << (is_bi ? "YES\n" : "NO\n");
    for (int i = 1; i <= v; ++i) adj[i].clear();
  }
  return 0;
}