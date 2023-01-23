#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[1005];
int dist[11][1005][1005];

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

void bfs(void) {
  // 차원, x, y
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  dist[0][0][0] = 1;
  while (!q.empty()) {
    int d, x, y;
    tie(d, x, y) = q.front();
    q.pop();
    // 벽을 뚫을 수 있는 차원
    if (d < k) {
      for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (OOB(nx, ny)) continue;
        if (dist[d + 1][nx][ny]) continue;
        dist[d + 1][nx][ny] = dist[d][x][y] + 1;
        q.push({d + 1, nx, ny});
      }
    }
    // 모든 벽을 부수고 난 후
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (dist[d][nx][ny] || board[nx][ny] != '0') continue;
      dist[d][nx][ny] = dist[d][x][y] + 1;
      q.push({d, nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> board[i];
  bfs();
  int min_dist = INT_MAX;
  // 벽 뚤는 차원(k) + 1(벽 안 뚫고 간 차원)
  for (int i = 0; i <= k; ++i)
    if (dist[i][n - 1][m - 1]) min_dist = min(min_dist, dist[i][n - 1][m - 1]);
  cout << (min_dist == INT_MAX ? -1 : min_dist);
  return 0;
}