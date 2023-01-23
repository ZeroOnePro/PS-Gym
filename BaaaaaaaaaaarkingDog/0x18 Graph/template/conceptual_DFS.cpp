#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool visited[10];

void dfs(void) {
  stack<int> s;
  s.push(1);
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    if (visited[cur]) continue;
    // 이렇게 실제로 방문할 때 방문표시를 남김으로서 관념적인 DFS의 방문순서를
    // 구현할 수 있다
    visited[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur]) {
      if (visited[nxt]) continue;
      s.push(nxt);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}