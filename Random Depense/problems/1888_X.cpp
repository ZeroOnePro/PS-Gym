#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 105;

int n, m, day, comp = true;
string board[range];
string copied[range];
bool vis[range][range];

void print() {
  cout << '\n';
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= m || y >= n; }

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(queue<pi2>& q) {
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    int v = board[x][y] - '0';
    for (int r = -v; r <= v; ++r)
      for (int c = -v; c <= v; ++c) {
        int nx = x + r;
        int ny = y + c;
        if (OOB(nx, ny)) continue;
        copied[nx][ny] = max(copied[nx][ny], board[x][y]);
      }

    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] == '0' || vis[nx][ny]) continue;
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 0; i < m; ++i) cin >> board[i];
  while (comp) {
    int area = 0;
    queue<pi2> q;
    for (int i = 0; i < m; ++i) fill(vis[i], vis[i] + n, false);
    copy(board, board + range, copied);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (board[i][j] != '0' && !vis[i][j]) {
          area += 1;
          q.push({i, j});
          vis[i][j] = true;
          bfs(q);
        }
    copy(copied, copied + range, board);
    comp = area > 1;
    day += 1;
  }
  cout << day - 1;
  return 0;
}