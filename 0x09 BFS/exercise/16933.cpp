#include <bits/stdc++.h>

using namespace std;

const int range = 1005;

int n, m, k;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string plane[range];
int dist[2][11][range][range];

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

void bfs(void) {
  // 밤 0 or 낮 1, 차원, x, y
  queue<tuple<int, int, int, int>> q;
  q.push({1, 0, 0, 0});
  dist[1][0][0][0] = 1;
  while (!q.empty()) {
    int t, d, x, y;
    tie(t, d, x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (plane[nx][ny] == '0') {
        if (dist[1 - t][d][nx][ny] > 0) continue;
        q.push({1 - t, d, nx, ny});
        dist[1 - t][d][nx][ny] = dist[t][d][x][y] + 1;
      } else {
        if (d >= k) continue;
        if (t == 1) {
          if (dist[1 - t][d + 1][nx][ny] > 0) continue;
          q.push({1 - t, d + 1, nx, ny});
          dist[1 - t][d + 1][nx][ny] = dist[t][d][x][y] + 1;
        } else {
          if (dist[1 - t][d][x][y] > 0) continue;
          q.push({1 - t, d, x, y});
          dist[1 - t][d][x][y] = dist[t][d][x][y] + 1;
        }
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> plane[i];
  bfs();
  int min_dist = INT_MAX;
  // 벽 뚤는 차원(k) + 1(벽 안 뚫고 간 차원)
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j <= k; ++j)
      if (dist[i][j][n - 1][m - 1])
        min_dist = min(min_dist, dist[i][j][n - 1][m - 1]);
  cout << (min_dist == INT_MAX ? -1 : min_dist);
  return 0;
}