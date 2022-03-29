#include <bits/stdc++.h>

using namespace std;

int n, m, h;

int boxes[102][102][102];
int dist[102][102][102];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

void bfs(queue<tuple<int, int, int>>& q) {
  while (!q.empty()) {
    tuple<int, int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 6; ++dir) {
      int nz = get<0>(cur) + dz[dir];
      int nx = get<1>(cur) + dx[dir];
      int ny = get<2>(cur) + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
      if (dist[nz][nx][ny] >= 0 || boxes[nz][nx][ny] != 0) continue;
      q.push({nz, nx, ny});
      dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<tuple<int, int, int>> q;
  cin >> m >> n >> h;
  for (int z = 0; z < h; ++z) {
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        cin >> boxes[z][r][c];
        if (boxes[z][r][c] == 1) {
          q.push({z, r, c});
        } else if (boxes[z][r][c] == 0) {
          dist[z][r][c] = -1;
        }
      }
    }
  }
  bfs(q);
  int day = 0;
  for (int z = 0; z < h; ++z) {
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (dist[z][r][c] == -1) {
          cout << -1;
          return 0;
        }
        day = max(day, dist[z][r][c]);
      }
    }
  }
  cout << day << '\n';
  return 0;
}