#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int box[1002][1002];
int dist[1002][1002];

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<pair<int, int>>& q) {
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[cur.x][cur.y] + 1;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  queue<pair<int, int>> q;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> box[i][j];
      if (box[i][j] == 1)
        q.push({i, j});
      else if (box[i][j] == 0)
        dist[i][j] = -1;
    }
  }

  bfs(q);

  int day = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dist[i][j] == -1) {
        cout << -1;
        return 0;
      }
      day = max(day, dist[i][j]);
    }
  }

  cout << day << '\n';

  return 0;
}