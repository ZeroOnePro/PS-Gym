#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> ti3;

const int range = 1'005;

int n, m;
string board[range];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dist[2][range][range];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs() {
  queue<ti3> q;
  q.push({0, 0, 0});
  dist[1][0][0] = dist[0][0][0] = 1;
  while (!q.empty()) {
    auto [d, x, y] = q.front();
    if (x == n - 1 && y == m - 1) {
      cout << dist[d][x][y];
      return;
    }
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || dist[d][nx][ny] >= 1 || d == 1 && board[nx][ny] == '1')
        continue;
      if (d == 0 && board[nx][ny] == '1') {
        q.push({d + 1, nx, ny});
        dist[d + 1][nx][ny] = dist[d][x][y] + 1;
        continue;
      }
      q.push({d, nx, ny});
      dist[d][nx][ny] = dist[d][x][y] + 1;
    }
  }
  cout << -1;
}

void print(int d) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << dist[d][i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> board[i];
  bfs();
  return 0;
}