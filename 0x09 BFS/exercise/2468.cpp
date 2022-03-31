#include <bits/stdc++.h>

using namespace std;

// bfs
// flood fill

#define x first
#define y second

int n;

int ground[102][102];
bool visited[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<pair<int, int>>& q, int height) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (visited[nx][ny] || ground[nx][ny] <= height) continue;
      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  queue<pair<int, int>> q;
  int max_height = 0, area = 0, max_area = -1;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      cin >> ground[r][c];
      max_height = max(max_height, ground[r][c]);
    }
  }
  for (int h = 0; h <= max_height; ++h) {
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (!visited[r][c] && ground[r][c] > h) {
          q.push({r, c});
          visited[r][c] = true;
          bfs(q, h);
          area += 1;
        }
      }
    }
    for (int i = 0; i < n; ++i) fill(visited[i], visited[i] + n, false);
    q = queue<pair<int, int>>();
    max_area = max(max_area, area);
    area = 0;
  }
  cout << max_area;
  return 0;
}