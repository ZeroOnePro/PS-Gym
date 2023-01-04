#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define v2i vector<vector<int>>
#define v3i vector<vector<vector<int>>>
#define ti3 tuple<int, int, int>

const int range = 10;
const int n = range - 5;

v3i board(range, v2i(range, vi(range)));  // 원본 맵
v3i proxy(range, v2i(range, vi(range)));  // 새로운 조합으로 만들어진 가짜
bool is_used[n];
int order[n];
int dir[n];
int mn = INT_MAX;

// 시계방향으로 90도 회전(k=1)
// 여기서 반복문 돌리면 180(k=2), 270(k=3)도 구현 가능
v2i rotate(v2i v, int k) {
  v2i prev = v;
  for (int i = 0; i < k; ++i) {
    v2i rotate = prev;
    for (int row = 0; row < n; ++row)
      for (int col = 0; col < n; ++col) v[row][col] = rotate[n - 1 - col][row];
    prev = v;
  }
  return v;
}

// 출발점(4가지 경우)와 도착점(출발점에 의존) 선정하기
// 4가지 경우
// (0,0,0), (0,0,n), (0,n,0), (0,n,n)
ti3 st, en;
void decise_st(int c) {
  if (c == 0) {
    st = {0, 0, 0};
    en = {n - 1, n - 1, n - 1};
  } else if (c == 1) {
    st = {0, 0, n};
    en = {n - 1, n - 1, 0};
  } else if (c == 2) {
    st = {0, n, 0};
    en = {n - 1, 0, n - 1};
  } else {
    st = {0, n, n};
    en = {n - 1, 0, 0};
  }
}

// 미로 탈출 가능한지 체크
// 최단 거리 측정
int dz[] = {0, 0, 0, 0, 1, -1};
int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dist[range][range][range];

bool OOB(int z, int x, int y) {
  return z < 0 || x < 0 || y < 0 || z >= n || x >= n || y >= n;
}

void bfs() {
  queue<ti3> q;
  // 이거 벡터로 선언하면 할 필요없는데..
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) fill(dist[i][j], dist[i][j] + n + 1, -1);
  auto [z, x, y] = st;
  dist[z][x][y] = 0;
  q.push({z, x, y});
  while (!q.empty()) {
    tie(z, x, y) = q.front();
    q.pop();
    for (int d = 0; d < 6; ++d) {
      int nz = z + dz[d];
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (OOB(nz, nx, ny) || proxy[nz][nx][ny] == 0) continue;
      if (dist[nz][nx][ny] >= 0) continue;
      dist[nz][nx][ny] = dist[z][x][y] + 1;
      q.push({nz, nx, ny});
    }
  }
  tie(z, x, y) = en;
  if (dist[z][x][y] != -1) mn = min(dist[z][x][y], mn);
}

// 각 판의 방향 조합
// 4^5
void decise_dir(int cur) {
  if (cur == n) {
    // 탈출 가능한 케이스면 거리구하고 최단 거리 갱신 아니면 -1
    // 맵 구성
    for (int i = 0; i < n; ++i) proxy[i] = rotate(board[order[i]], dir[i]);
    // 시작점 결정하여 bfs 돌리기
    for (int i = 0; i < n - 1; ++i) {
      decise_st(i);
      auto [z, x, y] = st;
      if (proxy[z][x][y] == 1) bfs();
    }
    return;
  }
  for (int i = 0; i < n - 1; ++i) {
    dir[cur] = i;
    decise_dir(cur + 1);
  }
}

// 판을 쌓는 순서 조합
// 5!
void decise_order(int cur) {
  if (cur == n) {
    // 방향 조합
    decise_dir(0);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (is_used[i]) continue;
    is_used[i] = true;
    order[cur] = i;
    decise_order(cur + 1);
    is_used[i] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k) cin >> board[i][j][k];
  decise_order(0);
  if (mn == INT_MAX)
    cout << -1;
  else
    cout << mn;
  return 0;
}