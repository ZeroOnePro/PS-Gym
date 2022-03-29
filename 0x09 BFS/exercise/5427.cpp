#include <bits/stdc++.h>

using namespace std;

// bfs
// 최단거리
// 특이점
// 1. 4179랑 똑같은 문제
// 2. 마지막 좌표가 있는 것이 아닌 외곽이라면 탈출가능

#define x first
#define y second

int tc, w, h;

string building[1002];
int dist[2][1002][1002];  // 3차원이 0일 때 불, 1일 때 사람

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(queue<pair<int, int>>& q, bool is_fire) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (is_fire) {
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (dist[0][nx][ny] >= 0 || building[nx][ny] == '#') continue;
        q.push({nx, ny});
        dist[0][nx][ny] = dist[0][cur.x][cur.y] + 1;
      } else {
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
          cout << dist[1][cur.x][cur.y] + 1 << '\n';
          return 0;
        }
        if (dist[1][nx][ny] >= 0 || building[nx][ny] == '#') continue;
        // dist[0][nx][ny] != 0을 넣어준 이유는 빌딩에서 불이 없을 때 이동할 수
        // 있어야하는데 이 조건이 빠지면 불의 도달 여부를 확인할 수 없기때문에
        // 무조건 안 되는 경우로 간주된다.
        if (dist[0][nx][ny] != -1 &&
            dist[1][cur.x][cur.y] + 1 >= dist[0][nx][ny])
          continue;
        q.push({nx, ny});
        dist[1][nx][ny] = dist[1][cur.x][cur.y] + 1;
      }
    }
  }
  if (!is_fire) cout << "IMPOSSIBLE\n";
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> tc;
  while (tc--) {
    cin >> w >> h;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < h; ++j) {
        fill(dist[i][j], dist[i][j] + w, -1);
      }
    }
    for (int i = 0; i < h; ++i) cin >> building[i];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (building[i][j] == '*') {
          q.push({i, j});
          dist[0][i][j] = 0;
        } else if (building[i][j] == '#') {
          dist[0][i][j] = -1;
        }
      }
    }
    bfs(q, true);
    q = queue<pair<int, int>>();
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (building[i][j] == '@') {
          q.push({i, j});
          dist[1][i][j] = 0;
        } else if (building[i][j] == '#') {
          dist[1][i][j] = -1;
        }
      }
    }
    bfs(q, false);
  }
  return 0;
}