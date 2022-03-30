#include <bits/stdc++.h>

using namespace std;

// 2차원 bfs
// flood fill
// 영역의 개수, 너비 구하기

#define x first
#define y second

int m, n, k;

int paper[102][102];
bool visited[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(queue<pair<int, int>>& q) {
  int width = 0;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if (visited[nx][ny] || paper[nx][ny] == 1) continue;
      q.push({nx, ny});
      visited[nx][ny] = true;
      width += 1;
    }
  }
  return width;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> m >> n >> k;
  for (int i = 0; i < k; ++i) {
    int lx, ly, rx, ry;
    cin >> ly >> lx >> ry >> rx;
    // 굳이 안뒤집어도 영역의 너비랑 개수는 변하지 않는데, 헷갈림
    // 행이 문제임 => 뒤집어야함
    lx = m - lx;  // 왼쪽 아래
    rx = m - rx;  // 오른쪽 위
    for (int r = rx; r < lx; ++r) {
      for (int c = ly; c < ry; ++c) {
        paper[r][c] = 1;
      }
    }
  }

  int area = 0;
  vector<int> widths(102);
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (!visited[r][c] && paper[r][c] == 0) {
        q.push({r, c});
        visited[r][c] = true;
        widths[area] = bfs(q) + 1;
        area += 1;
      }
    }
  }

  sort(widths.begin(), widths.end());

  cout << area << '\n';

  for (int w : widths) {
    if (w != 0) cout << w << ' ';
  }
  return 0;
}