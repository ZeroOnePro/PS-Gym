#include <bits/stdc++.h>

using namespace std;

// 벽 부수고 이동하기(2206)에서 벽을 여러번 부술 수 있는 버전이네

int k, w, h, min_dist;

int board[202][202];
int dist[32][202][202];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int hdx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hdy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool is_out_of_bound(int x, int y) {
  return x < 0 or x >= h or y < 0 or y >= w;
}

void bfs(queue<tuple<int, int, int>>& q) {
  while (!q.empty()) {
    int chance, x, y;
    tie(chance, x, y) = q.front();
    q.pop();
    if (chance < k) {
      for (int dir = 0; dir < 8; ++dir) {
        int nx = x + hdx[dir];
        int ny = y + hdy[dir];
        if (is_out_of_bound(nx, ny)) continue;
        if (board[nx][ny] == 1 or dist[chance + 1][nx][ny] > 0) continue;
        dist[chance + 1][nx][ny] = dist[chance][x][y] + 1;
        q.push({chance + 1, nx, ny});
      }
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (is_out_of_bound(nx, ny)) continue;
      if (board[nx][ny] == 1 or dist[chance][nx][ny] > 0) continue;
      dist[chance][nx][ny] = dist[chance][x][y] + 1;
      q.push({chance, nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<tuple<int, int, int>> q;
  cin >> k >> w >> h;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) cin >> board[i][j];
  q.push({0, 0, 0});
  dist[0][0][0] = 1;
  bfs(q);
  min_dist = INT_MAX;
  for (int i = 0; i <= k; ++i)
    if (dist[i][h - 1][w - 1]) min_dist = min(min_dist, dist[i][h - 1][w - 1]);

  cout << (min_dist == INT_MAX ? -1 : min_dist - 1);
  return 0;
}