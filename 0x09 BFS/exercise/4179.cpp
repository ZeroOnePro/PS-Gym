#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n, m;
string maze[1002];
int escape[1002][1002];
int fire[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(queue<pair<int, int>>& q, bool is_fire) {
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (is_fire) {
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (fire[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
        fire[nx][ny] = fire[cur.x][cur.y] + 1;
        q.push({nx, ny});
      } else {
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
          // 범위가 벗어났다는 것은 탈출에 성공했음을 의미
          // 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 된다.
          cout << escape[cur.x][cur.y] + 1;
          return 0;
        };
        if (escape[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
        if (fire[nx][ny] != -1 && fire[nx][ny] <= escape[cur.x][cur.y] + 1)
          continue;
        escape[nx][ny] = escape[cur.x][cur.y] + 1;
        q.push({nx, ny});
      }
    }
  }
  if (!is_fire) cout << "IMPOSSIBLE\n";
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q_fire;
  queue<pair<int, int>> q_escape;

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    fill(fire[i], fire[i] + m, -1);
    fill(escape[i], escape[i] + m, -1);
  }

  for (int i = 0; i < n; ++i) cin >> maze[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == 'F') {
        q_fire.push({i, j});
        fire[i][j] = 0;
      } else if (maze[i][j] == 'J') {
        q_escape.push({i, j});
        escape[i][j] = 0;
      }
    }
  }

  bfs(q_fire, true);
  bfs(q_escape, false);

  return 0;
}