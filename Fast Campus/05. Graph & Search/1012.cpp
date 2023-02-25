#include <bits/stdc++.h>

using namespace std;

// flood fill
// 구역 개수 구하기

#define x first
#define y second

int m, n, k, area;  // m이 열 n이 행, k는 배추 위치의 개수

int field[51][51];
bool visited[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<pair<int, int>>& q) {
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (visited[nx][ny] || field[nx][ny] != 1) continue;
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  queue<pair<int, int>> q;
  cin >> tc;
  while (tc--) {
    cin >> m >> n >> k;
    while (k--) {
      int r, c;
      cin >> c >> r;
      field[r][c] = 1;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!visited[i][j] && field[i][j] == 1) {
          q.push({i, j});
          visited[i][j] = true;
          bfs(q);
          area += 1;
        }
      }
    }
    cout << area << '\n';
    area = 0;
    for (int i = 0; i < n; ++i) {
      fill(field[i], field[i] + m, 0);
      fill(visited[i], visited[i] + m, false);
    }
    q = queue<pair<int, int>>();
  }
  return 0;
}