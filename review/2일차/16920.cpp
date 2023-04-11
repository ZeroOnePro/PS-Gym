#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> ti3;

const int range = 1'005;

int n, m, p;
int s[15];
int cnt[15];
set<tuple<int, int, int>> nxt[15];
string board[range];
bool vis[range][range];

void print(auto a) {
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << a[i][j] << ' ';
    cout << '\n';
  }
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(queue<ti3>& q) {
  while (!q.empty()) {
    auto [x, y, age] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] != '.' || age == 0)
        continue;
      if (age == 1)
        nxt[board[x][y] - '0'].insert({nx, ny, s[board[x][y] - '0']});
      vis[nx][ny] = true;
      cnt[board[x][y] - '0'] += 1;
      board[nx][ny] = board[x][y];
      q.push({nx, ny, age - 1});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> p;
  for (int i = 1; i <= p; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) cin >> board[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (isdigit(board[i][j])) {
        nxt[board[i][j] - '0'].insert({i, j, s[board[i][j] - '0']});
        cnt[board[i][j] - '0'] += 1;
      }
  while (true) {
    queue<ti3> q;
    int cnt = 0;
    for (int i = 1; i <= p; ++i)
      if (!nxt[i].empty()) {
        for (auto [x, y, age] : nxt[i]) q.push({x, y, age});
        nxt[i].clear();
        bfs(q);
      } else
        cnt += 1;
    if (cnt == p) break;
  }
  for (int i = 1; i <= p; ++i) cout << cnt[i] << ' ';
  return 0;
}