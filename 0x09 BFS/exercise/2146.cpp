#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n;

int country[102][102];
int dist[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<pair<int, int>>& q) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (dist[nx][ny] >= 0) }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}