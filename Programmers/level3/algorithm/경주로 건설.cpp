#include <bits/stdc++.h>

using namespace std;

// 이전 칸에서 현재칸으로 올 때 방향과 현재 칸에서 다음 칸으로 가는 방향
// 기억하기

const int range = 30;

int n, mn = INT_MAX;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dist[4][range][range];

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

void dfs(vector<vector<int>>& board, int x, int y, int d) {
  if (x == n - 1 && y == n - 1) return;
  for (int dir = 0; dir < 4; ++dir) {
    if (x == 0 && y == 0) d = dir;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny) || board[nx][ny] == 1) continue;
    if (dist[dir][nx][ny] < dist[d][x][y] + 100 + (dir != d) * 500) continue;
    dist[dir][nx][ny] = dist[d][x][y] + 100 + (dir != d) * 500;
    dfs(board, nx, ny, dir);
  }
}

int solution(vector<vector<int>> board) {
  int answer = 0;
  n = board[0].size();
  for (int dir = 0; dir < 4; ++dir) {
    for (int i = 0; i < n; ++i) fill(dist[dir][i], dist[dir][i] + n, INT_MAX);
    dist[dir][0][0] = 0;
  }
  dfs(board, 0, 0, -1);
  for (int dir = 0; dir < 4; ++dir) mn = min(mn, dist[dir][n - 1][n - 1]);
  answer = mn;
  return answer;
}