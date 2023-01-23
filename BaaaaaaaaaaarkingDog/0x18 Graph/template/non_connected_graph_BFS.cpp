#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool visited[10];
int v = 9;  // 정점의 개수

// 인접 리스트에서의 bfs
// 아직 방문하지 않은 노드를 시작점으로 넣으면서 반복
void bfs(void) {
  queue<int> q;
  for (int i = 1; i <= v; ++i) {
    if (visited[i]) continue;
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      cout << cur << ' ';
      for (auto nxt : adj[cur]) {
        if (visited[nxt] != -1) continue;
        q.push(nxt);
        visited[nxt] = true;
      }
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