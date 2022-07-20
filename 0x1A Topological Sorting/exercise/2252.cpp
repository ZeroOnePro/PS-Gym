#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32002];
int deg[32002];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e;
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    deg[to] += 1;
  }
  queue<int> q;
  vector<int> result;
  for (int i = 1; i <= v; ++i)
    if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    result.push_back(cur);
    for (int nxt : adj[cur]) {
      deg[nxt] -= 1;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
  for (int i : result) {
    cout << i << ' ';
  }
  return 0;
}