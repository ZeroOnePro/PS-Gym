#include <bits/stdc++.h>

using namespace std;

const int range = 505;

int n, m;
int plane[range][range];
int dp[range][range];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int dfs(int x, int y) {
  if (x == n - 1 && y == m - 1) return 1;
  if (dp[x][y] != -1) return dp[x][y];
  dp[x][y] = 0;
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny)) continue;
    if (plane[x][y] <= plane[nx][ny]) continue;
    dp[x][y] += dfs(nx, ny);
  }
  return dp[x][y];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> plane[i][j];
      dp[i][j] = -1;
    }
  dfs(0, 0);
  cout << dp[0][0];
  return 0;
}