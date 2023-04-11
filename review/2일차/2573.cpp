#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 305;

int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int board[range][range];
bool vis[range][range];
int melt[range][range];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(pi2 st) {
  queue<pi2> q;
  auto [x, y] = st;
  q.push({x, y});
  vis[x][y] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny]) continue;
      if (board[nx][ny] == 0) {
        melt[x][y] += 1;
        continue;
      }
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int day = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> board[i][j];
  while (true) {
    int cnt = 0, area = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (board[i][j] != 0 && !vis[i][j]) {
          area += 1;
          bfs({i, j});
        }
      }
    if (area >= 2) {
      cout << day;
      return 0;
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        board[i][j] -= melt[i][j];
        if (board[i][j] < 0) board[i][j] = 0;
        if (board[i][j] > 0) cnt += 1;
      }
    if (cnt == 0) break;
    day += 1;
    for (int i = 0; i < n; ++i) {
      fill(vis[i], vis[i] + m, false);
      fill(melt[i], melt[i] + m, 0);
    }
  }
  cout << 0;
  return 0;
}