#include <bits/stdc++.h>

using namespace std;

const int range = 505;

int n, m;
int plane[range][range];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dp[range][range];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(queue<pair<int, int>>& q) {
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if ((plane[x][y] <= plane[nx][ny])) continue;
      if (dp[nx][ny]) {
        dp[nx][ny] += dp[x][y];
        continue;
      } else {
        dp[nx][ny] = dp[x][y];
      }
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> plane[i][j];
  q.push({0, 0});
  dp[0][0] = 1;
  bfs(q);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << dp[i][j] << ' ';
    cout << '\n';
  }
  cout << dp[n - 1][m - 1];
  return 0;
}