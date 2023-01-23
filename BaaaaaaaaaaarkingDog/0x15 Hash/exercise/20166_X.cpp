#include <bits/stdc++.h>

using namespace std;

int n, m, k;
string plane[15];
unordered_map<string, int> paths;

int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

pair<int, int> transform(int x, int y) {
  if (x < 0) x = n - 1;
  if (x >= n) x = 0;
  if (y < 0) y = m - 1;
  if (y >= m) y = 0;
  return {x, y};
}

void dfs(int x, int y, string path) {
  if (path.length() == 5) {
    paths[path] += 1;
    return;
  }
  paths[path] += 1;
  for (int dir = 0; dir < 8; ++dir) {
    auto [nx, ny] = transform(x + dx[dir], y + dy[dir]);
    dfs(nx, ny, path + plane[nx][ny]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> plane[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      string tmp = "";
      tmp.push_back(plane[i][j]);
      dfs(i, j, tmp);
    }
  while (k--) {
    string s;
    cin >> s;
    cout << paths[s] << '\n';
  }
  return 0;
}