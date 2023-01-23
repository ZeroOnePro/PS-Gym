#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[500][500];
bool visited[500][500];

int n, m;

int bfs(queue<pair<int, int>> &q) {
  int width = 1;
  while (!q.empty()) {
    pair<int, int> cursor = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cursor.x + dx[dir];
      int ny = cursor.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (visited[nx][ny] || board[nx][ny] != 1) continue;
      visited[nx][ny] = true;
      q.push({nx, ny});
      width += 1;
    }
  }
  return width;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  int cnt = 0;
  int max_width = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j] && board[i][j]) {
        visited[i][j] = true;
        q.push({i, j});
        int width = bfs(q);
        max_width = max(width, max_width);
        cnt++;
      }
    }
  }
  cout << cnt << '\n' << max_width;
  return 0;
}