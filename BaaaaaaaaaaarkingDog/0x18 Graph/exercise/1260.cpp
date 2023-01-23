#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void recursive_dfs(int start) {
  visited[start] = true;
  cout << start << ' ';
  for (int nxt : adj[start]) {
    if (visited[nxt]) continue;
    recursive_dfs(nxt);
  }
}

void dfs(int start) {
  stack<int> s;
  s.push(start);
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    if (visited[cur]) continue;
    visited[cur] = true;
    cout << cur << ' ';
    for (int i = 0; i < adj[cur].size(); ++i) {
      // 스택의 특성상 거꾸로 넣어야됨(LIFO)
      int nxt = adj[cur][adj[cur].size() - 1 - i];
      if (visited[nxt]) continue;
      s.push(nxt);
    }
  }
}

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << ' ';
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
  int v, e, start;
  cin >> v >> e >> start;
  while (e--) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  for (int i = 1; i <= v; ++i) sort(adj[i].begin(), adj[i].end());
  dfs(start);
  fill(visited, visited + v + 1, false);
  cout << '\n';
  bfs(start);
  return 0;
}