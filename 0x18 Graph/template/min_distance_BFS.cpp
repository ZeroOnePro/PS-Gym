#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
int dist[10];

// 인접 리스트에서의 bfs
// 1번 정점과의 최단 거리
void bfs(void) {
  fill(dist, dist + 10, -1);
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto nxt : adj[cur]) {
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[nxt] + 1;
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