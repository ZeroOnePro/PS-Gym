#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n, m, x, y, k;
int board[range][range];

// 동서북남으로 정의해야 편함
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

// 주사위(정육면체) 각 면에 쓰여있는 수
struct square {
  int top;
  int bottom;
  int left;
  int right;
  int front;
  int back;
} sq;

// 주사위를 굴린다
// 동서북남(1234) 각각에 대해 정의해야함
void roll(int dir, struct square& cur) {
  struct square tmp = cur;
  // 동
  if (dir == 1) {
    cur.top = tmp.left;
    cur.bottom = tmp.right;
    cur.left = tmp.bottom;
    cur.right = tmp.top;
  }
  // 서
  else if (dir == 2) {
    cur.top = tmp.right;
    cur.bottom = tmp.left;
    cur.left = tmp.top;
    cur.right = tmp.bottom;
  }
  // 북
  else if (dir == 3) {
    cur.top = tmp.back;
    cur.bottom = tmp.front;
    cur.front = tmp.top;
    cur.back = tmp.bottom;
  }
  // 남
  else {
    cur.top = tmp.front;
    cur.bottom = tmp.back;
    cur.front = tmp.bottom;
    cur.back = tmp.top;
  }
}

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

// 주어진 방향으로 맵에서 이동
bool move(int dir) {
  dir -= 1;
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  if (OOB(nx, ny)) return false;
  x = nx;
  y = ny;
  return true;
}

// 지시된 대로 주사위의 면이나 맵의 숫자 변경
// 1. 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에
//    복사
// 2. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며,
//    칸에 쓰여 있는 수는 0이 된다.
void check(struct square& cur) {
  if (board[x][y] == 0)
    board[x][y] = cur.bottom;
  else {
    cur.bottom = board[x][y];
    board[x][y] = 0;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> x >> y >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> board[i][j];
  while (k--) {
    int dir;
    cin >> dir;
    // to - do
    // 1. 이동하기 => 굴릴 수 있는지 판단해야하네?
    // 1. 굴리기
    // 3. 숫자 변경
    if (move(dir)) {
      roll(dir, sq);
      check(sq);
      cout << sq.top << '\n';
    }
  }
  return 0;
}