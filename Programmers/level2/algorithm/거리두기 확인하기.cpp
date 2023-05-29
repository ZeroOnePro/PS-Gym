#include <bits/stdc++.h>

using namespace std;

const int range = 5;

int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int vis[range + 5][range + 5];

bool OOB(int x, int y) { return x < 0 || x >= range || y < 0 || y >= range; }

bool bfs(int sx, int sy, vector<string>& p) {
  queue<tuple<int, int, int>> q;
  for (int i = 0; i < range; ++i) fill(vis[i], vis[i] + range, false);
  q.push({sx, sy, 2});
  vis[sx][sy] = true;
  while (!q.empty()) {
    auto [x, y, age] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || p[nx][ny] == 'X' || age == 0) continue;
      if (p[nx][ny] == 'P') return false;
      q.push({nx, ny, age - 1});
      vis[nx][ny] = true;
    }
  }
  return true;
}

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;
  for (vector<string> p : places) {
    bool res = true;
    for (int i = 0; i < range; ++i)
      for (int j = 0; j < range; ++j)
        if (p[i][j] == 'P') res &= bfs(i, j, p);
    answer.push_back(res);
  }

  return answer;
}