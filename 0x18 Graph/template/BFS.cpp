#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool visited[10];

// 인접 리스트에서의 bfs
void bfs(void) {
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << ' ';
    for (auto nxt : adj[cur]) {
      if (visited[nxt]) continue;
      q.push(nxt);
      visited[nxt] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int from, to;
  int n;
  cin >> n;
  while (n--) {
    cin >> from >> to;
    // 무방향 그래프를 가정
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  bfs();
  return 0;
}