#include <bits/stdc++.h>

using namespace std;

const int range = 55;

enum { WALL = 1 };

int n, m, d, r, c, cnt;

int room[range][range];
bool vis[range][range];  // 청소가 됐는지 안 됐는지 판단

// 북서남동 순으로 왼쪽 방향 반시계 회전
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void decise_dir() { d = (d + 1) % 4; }

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

bool move() {
  // 현재 칸에서 반시계로 돌면서 4방향 모두 검사
  for (int i = 0; i < 4; ++i) {
    decise_dir();
    int nx = r + dx[d];
    int ny = c + dy[d];
    if (OOB(nx, ny) || room[nx][ny] == WALL) continue;
    // 왼쪽으로 돌았더니 청소가 가능한 경우 이동
    if (!vis[nx][ny]) {
      vis[nx][ny] = true;
      cnt += 1;
      r = nx;
      c = ny;
      return true;
    }
  }
  // 후진이 필요한 경우
  int back_dir = (d + 2) % 4;
  int nx = r + dx[back_dir];
  int ny = c + dy[back_dir];
  // 후진 불가능하면 청소 끝내기 => 후진이 불가능한 경우
  if (OOB(nx, ny) || room[nx][ny] == WALL) return false;
  // 후진 가능할 때 후진 => 현재 보고 있는 방향의 반대로 이동
  r = nx;
  c = ny;
  return true;
}

void print() {
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << vis[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  cin >> r >> c >> d;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> room[i][j];
  // 반시계 방향 회전 때문에 동과 서 서로 교체했음
  if (d == 1)
    d = 3;
  else if (d == 3)
    d = 1;
  vis[r][c] = true;
  cnt += 1;
  while (move()) {
  };
  cout << cnt;
  return 0;
}