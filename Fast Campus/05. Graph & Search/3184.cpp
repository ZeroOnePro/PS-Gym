#include <bits/stdc++.h>

using namespace std;

const int range = 255;

typedef pair<int, int> pi2;

int r, c;
string yard[range];
bool vis[range][range];
int winner[range][2];  // 각 영역 탐색 후  살아남는 양과 늑대의 수  저장

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= r || y >= c; }
void bfs(int x, int y, int group) {
  queue<pi2> q;
  q.push({x, y});
  if (yard[x][y] == 'o') winner[group][0] += 1;
  if (yard[x][y] == 'v') winner[group][1] += 1;
  vis[x][y] = true;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || yard[nx][ny] == '#') continue;
      if (yard[nx][ny] == 'o') winner[group][0] += 1;
      if (yard[nx][ny] == 'v') winner[group][1] += 1;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> r >> c;
  int cnt = 0;
  for (int i = 0; i < r; ++i) cin >> yard[i];
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if ((yard[i][j] == 'o' || yard[i][j] == 'v') && !vis[i][j])
        bfs(i, j, cnt++);
  // 각 그룹마다 양과 늑대의 수 체크하여 더 큰 거 누적시키기
  int sheep = 0, wolf = 0;
  for (int i = 0; i < cnt; ++i) {
    if (winner[i][0] > winner[i][1])
      sheep += winner[i][0];
    else
      wolf += winner[i][1];
  }
  cout << sheep << ' ' << wolf;
  return 0;
}