#include <bits/stdc++.h>

using namespace std;

const int range = 105;

// start -> 레버 + 레버 -> end 최단 거리 합
// 두 경로 중 하나라도 불가능하면 불가능 케이스

pair<int, int> point[3];
int r, c;

// 시작점 0, 벽 1, 레버 2, 출구 3으로 정의
int board[range][range];

int dist[range][range];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

int bfs(int sx, int sy, int ex, int ey) {
  queue<pair<int, int>> q;
  for (int i = 0; i < range; ++i) fill(dist[i], dist[i] + range, -1);
  q.push({sx, sy});
  dist[sx][sy] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[x][y] + 1;
    }
  }
  return dist[ex][ey];
}

int solution(vector<string> maps) {
  int answer = 0;
  r = maps.size(), c = maps[0].size();
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      if (maps[i][j] == 'S')
        point[0] = {i, j};
      else if (maps[i][j] == 'L')
        point[1] = {i, j};
      else if (maps[i][j] == 'E')
        point[2] = {i, j};
      else if (maps[i][j] == 'X')
        board[i][j] = 1;
    }
  for (int i = 0; i < 2; ++i) {
    auto [sx, sy] = point[i];
    auto [ex, ey] = point[i + 1];
    int d = bfs(sx, sy, ex, ey);
    if (d == -1) return -1;
    answer += d;
  }
  return answer;
}