#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 105;

int n, m;
string board[range];
int dist[range][range];
vector<pi2> st;

void print() {
  cout << '\n';
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cout << dist[i][j] << ' ';
    cout << '\n';
  }
}

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= m || y >= n; }

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_connected() {
  if (st.size() == 0) return true;
  queue<pi2> q;
  bool vis[range][range];
  for (int i = 0; i < m; ++i) fill(vis[i], vis[i] + n, false);
  auto [x, y] = st[0];
  q.push({x, y});
  vis[x][y] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] == '0' || vis[nx][ny]) continue;
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  bool res = true;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (board[i][j] != '0') res &= vis[i][j];
  return res;
}

void bfs() {
  if (is_connected()) return;
  queue<pi2> q;
  for (int i = 0; i < m; ++i) fill(dist[i], dist[i] + n, -1);
  for (auto [x, y] : st) {
    q.push({x, y});
    dist[x][y] = 0;
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    int v = board[x][y] - '0';
    for (int r = -v; r <= v; ++r)
      for (int c = -v; c <= v; ++c) {
        int nx = x + r;
        int ny = y + c;
        if (OOB(nx, ny)) continue;
        dist[nx][ny] = dist[x][y] + 1;
        board[nx][ny] = board[x][y];
        if (is_connected()) return;
      }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    cin >> board[i];
    for (int j = 0; j < n; ++j)
      if (board[i][j] != '0') st.push_back({i, j});
  }
  bfs();
  int mx = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (dist[i][j] >= 0) mx = max(mx, dist[i][j]);
  cout << mx;
  return 0;
}