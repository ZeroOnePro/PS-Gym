#include <bits/stdc++.h>

using namespace std;

// flood fill
// 구역의 개수 구하기

#define x first
#define y second

int n, area, color_blindness_area;
string picture[101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<pair<int, int>>& q, char rgb, bool is_blind) {
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (is_blind) {
        if (rgb == 'G' || rgb == 'R') {
          if (visited[nx][ny] || picture[nx][ny] == 'B') continue;
        } else {
          if (visited[nx][ny] || picture[nx][ny] != rgb) continue;
        }
      } else {
        if (visited[nx][ny] || picture[nx][ny] != rgb) continue;
      }
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> picture[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[i][j]) {
        visited[i][j] = true;
        q.push({i, j});
        bfs(q, picture[i][j], false);
        area += 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    fill(visited[i], visited[i] + n, false);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[i][j]) {
        visited[i][j] = true;
        q.push({i, j});
        bfs(q, picture[i][j], true);
        color_blindness_area += 1;
      }
    }
  }
  q = queue<pair<int, int>>();
  cout << area << ' ' << color_blindness_area << '\n';
  return 0;
}