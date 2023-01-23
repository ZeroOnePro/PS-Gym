#include <bits/stdc++.h>

using namespace std;

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string building[1002];
int dist[2][1002][1002];  // 3차원은 벽을 부쉈는지 아닌지 확인하는 변수

int bfs(queue<tuple<int, int, int>>& q) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int broken, x, y;
      tie(broken, x, y) = cur;
      if (x == n - 1 && y == m - 1) {
        return dist[broken][x][y] + 1;
      }
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      // 벽 아직 안 부쉈거나(broken = 0) 부순 후(broken = 1)
      if (building[nx][ny] == '0' && dist[broken][nx][ny] == -1) {
        q.push({broken, nx, ny});
        dist[broken][nx][ny] = dist[broken][x][y] + 1;
      }
      // 벽을 부술 수 있는 경우
      if (!broken && building[nx][ny] == '1' && dist[1][nx][ny] == -1) {
        q.push({1, nx, ny});
        dist[1][nx][ny] = dist[broken][x][y] + 1;
      }
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<tuple<int, int, int>> q;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> building[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dist[0][i][j] = dist[1][i][j] = -1;
    }
  }

  q.push({0, 0, 0});
  dist[1][0][0] = dist[0][0][0] = 0;
  cout << bfs(q);

  return 0;
}
