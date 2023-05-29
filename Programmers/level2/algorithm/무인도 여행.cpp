#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 105;

int n, m;

string board[range];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int vis[range][range];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(int sx, int sy) {
  queue<pi2> q;
  int day = board[sx][sy] - '0';
  q.push({sx, sy});
  vis[sx][sy] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 'X') continue;
      day += board[nx][ny] - '0';
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  return day;
}

vector<int> solution(vector<string> maps) {
  vector<int> answer;
  n = maps.size();
  m = maps[0].size();
  for (int i = 0; i < n; ++i) board[i] = maps[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (!vis[i][j] && board[i][j] != 'X') answer.push_back(bfs(i, j));
    }
  if (answer.empty())
    answer.push_back(-1);
  else
    sort(answer.begin(), answer.end());
  return answer;
}