#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
int parent[100001];

void bfs(void) {
  queue<int> q;
  q.push(1);
  parent[1] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (parent[nxt] != 0) continue;
      q.push(nxt);
      parent[nxt] = cur;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  bfs();
  for (int i = 2; i <= n; ++i) {
    cout << parent[i] << '\n';
  }
  return 0;
}