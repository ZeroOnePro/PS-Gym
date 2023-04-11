#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

int n, m, k;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

string board[range];
int dist[2][11][range][range];

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

void bfs(void) {
  // 낮/밤, 차원, x, y
  queue<tuple<int, int, int, int>> q;
  q.push({0, 0, 0, 0});
  dist[0][0][0][0] = 1;
  while (!q.empty()) {
    auto [t, d, x, y] = q.front();
    q.pop();
    if (d < k) {
      for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (OOB(nx, ny)) continue;
        bool is_daytime = t == 0;
        if (!is_daytime) {
          nx = x;
          ny = y;
        }
        if (dist[1 - t][d + is_daytime][nx][ny] > 0) continue;
        dist[1 - t][d + is_daytime][nx][ny] = dist[t][d][x][y] + 1;
        q.push({1 - t, d + is_daytime, nx, ny});
      }
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (dist[1 - t][d][nx][ny] > 0 || board[nx][ny] != '0') continue;
      dist[1 - t][d][nx][ny] = dist[t][d][x][y] + 1;
      q.push({1 - t, d, nx, ny});
    }
  }
}

void print() {
  for (int t = 0; t < 2; ++t)
    for (int d = 0; d <= k; ++d) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << dist[t][d][i][j] << ' ';
        cout << '\n';
      }
      cout << '\n';
    }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> board[i];
  bfs();
  // print();
  int min_dist = INT_MAX;
  // 벽 뚤는 차원(k) + 1(벽 안 뚫고 간 차원)
  for (int t = 0; t < 2; ++t)
    for (int d = 0; d <= k; ++d)
      if (dist[t][d][n - 1][m - 1] > 0)
        min_dist = min(min_dist, dist[t][d][n - 1][m - 1]);
  cout << (min_dist == INT_MAX ? -1 : min_dist);
  return 0;
}