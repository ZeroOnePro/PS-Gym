#include <bits/stdc++.h>

using namespace std;

// 탐색 순서가 중요 d -> l -> r -> u
// 한 칸을 여러번 방문할 수 있음 && 그래프 탐색 => 백트래킹, prunning

bool is_find = false;
string answer = "";

bool OOB(int x, int y, int n, int m) {
  return x < 1 || x > n || y < 1 || y > m;
}

int manhaton(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

string dirs[4] = {"d", "l", "r", "u"};

void dfs(int x, int y, int r, int c, int n, int m, int k, string sp) {
  int dist = manhaton(x, y, r, c);
  if (is_find) return;
  if (dist + sp.length() > k) return;
  if (sp.length() > k) return;
  if (!is_find && sp.length() == k) {
    if (x == r && y == c) {
      is_find = true;
      answer = sp;
    }
    return;
  }
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny, n, m)) continue;
    dfs(nx, ny, r, c, n, m, k, sp + dirs[dir]);
  }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
  int dist = k - manhaton(x, y, r, c);
  if (!(dist < 0 or dist & 1)) dfs(x, y, r, c, n, m, k, "");
  return is_find ? answer : "impossible";
}