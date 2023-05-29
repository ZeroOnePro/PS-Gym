#include <bits/stdc++.h>

using namespace std;

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dist[105][105];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(vector<vector<int>>& maps) {
  queue<pair<int, int>> q;
  q.push({n - 1, m - 1});
  dist[n - 1][m - 1] = 1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (maps[nx][ny] == 0 || dist[nx][ny] >= 1) continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[x][y] + 1;
    }
  }
}

int solution(vector<vector<int>> maps) {
  int answer = 0;
  n = maps.size();
  m = maps[0].size();
  bfs(maps);
  answer = dist[0][0] == 0 ? -1 : dist[0][0];
  return answer;
}