#include <bits/stdc++.h>

using namespace std;

const int range = 55;

int r, c, t;
int board[range][range];
pair<int, int> st[2];

void print() {
  cout << '\n';
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}

void input() {
  int idx = 0;
  cin >> r >> c >> t;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      cin >> board[i][j];
      if (board[i][j] == -1) st[idx++] = {i, j};
    }
}

// 공청기 순환
// 반시계(d == 0), 시계(d == 1)
void inhale(int x, int y, int d) {
  int cur = board[x][1], prev;
  // 오른쪽으로 순환
  board[x][1] = 0;
  for (int i = 1; i < c - 1; ++i) {
    prev = board[x][i + 1];
    board[x][i + 1] = cur;
    cur = prev;
  }
  if (d == 0) {
    // 오른쪽 끝에서 위로 순환
    for (int i = x; i >= 1; --i) {
      prev = board[i - 1][c - 1];
      board[i - 1][c - 1] = cur;
      cur = prev;
    }
  } else {
    // 오른쪽 끝에서 아래로 순환
    for (int i = x; i < r - 1; ++i) {
      prev = board[i + 1][c - 1];
      board[i + 1][c - 1] = cur;
      cur = prev;
    }
  }
  // 왼쪽으로 순환
  int idx = d == 0 ? 0 : r - 1;
  for (int i = c - 1; i >= 1; --i) {
    prev = board[idx][i - 1];
    board[idx][i - 1] = cur;
    cur = prev;
  }
  if (d == 0) {
    // 왼쪽 끝에서 아래로 순환
    for (int i = 0; i < x - 1; ++i) {
      prev = board[i + 1][0];
      board[i + 1][0] = cur;
      cur = prev;
    }
  } else {
    // 왼쪽 끝에서 위로 순환
    for (int i = r - 1; i > x + 1; --i) {
      prev = board[i - 1][0];
      board[i - 1][0] = cur;
      cur = prev;
    }
  }
}

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= r || y >= c; }
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

// 먼지 확산
void spread() {
  // (x, y)의 인접칸에서 퍼져오는 먼지양 누적
  int acc[range][range];
  for (int i = 0; i < r; ++i) fill(acc[i], acc[i] + c, 0);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      // 퍼질게 없거나 공청기일 때는 할 필요없음
      if (board[i][j] <= 0) continue;
      int cnt = 0;
      int dust = board[i][j] / 5;
      for (int dir = 0; dir < 4; ++dir) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        // 확산될 수 있는 칸의 수를 세고 인접 칸에서 오는 먼지 누적시키기
        if (OOB(nx, ny) || board[nx][ny] == -1) continue;
        acc[nx][ny] += dust;
        cnt += 1;
      }
      board[i][j] -= dust * cnt;
    }
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) board[i][j] += acc[i][j];
}

int clac_dust_amount() {
  int sum = 0;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) sum += board[i][j];
  return sum;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  while (t--) {
    spread();
    for (int i = 0; i < 2; ++i) {
      auto [x, y] = st[i];
      inhale(x, y, i);
    }
  }
  cout << clac_dust_amount() + 2;
  return 0;
}