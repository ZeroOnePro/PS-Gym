#include <bits/stdc++.h>

using namespace std;

// bfs
// 3차원 bfs
// 최단경로

int l, r, c;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

string building[32][32];
int dist[32][32][32];

void bfs(queue<tuple<int, int, int>>& q) {
  int is_trap = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    int z, x, y;
    tie(z, x, y) = cur;
    for (int dir = 0; dir < 6; ++dir) {
      int nz = z + dz[dir];
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nz < 0 || nz > l || nx < 0 || nx > r || ny < 0 || ny > c) continue;
      if (building[nz][nx][ny] == 'E') {
        is_trap = false;
        cout << "Escaped in " + to_string(dist[z][x][y] + 1) << " minute(s).\n";
        return;
      }
      if (dist[nz][nx][ny] >= 0) continue;
      q.push({nz, nx, ny});
      dist[nz][nx][ny] = dist[z][x][y] + 1;
    }
  }
  if (is_trap) cout << "Trapped!\n";
  return;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<tuple<int, int, int>> q;
  while (true) {
    cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0) break;
    for (int z = 0; z < l; ++z) {
      for (int x = 0; x < r; ++x) {
        cin >> building[z][x];
        for (int y = 0; y < c; ++y) {
          if (building[z][x][y] == 'S') {
            q.push({z, x, y});
            dist[z][x][y] = 0;
          }
          if (building[z][x][y] == '.') {
            dist[z][x][y] = -1;
          }
        }
      }
    }
    bfs(q);
    // 초기화 로직
    for (int z = 0; z < l; ++z) {
      for (int x = 0; x < r; ++x) {
        fill(dist[z][x], dist[z][x] + c, 0);
      }
    }
    q = queue<tuple<int, int, int>>();
  }

  return 0;
}
