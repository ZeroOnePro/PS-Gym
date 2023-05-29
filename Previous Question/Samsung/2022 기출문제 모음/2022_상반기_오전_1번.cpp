#include <bits/stdc++.h>

using namespace std;

const int range = 100;

typedef pair<int, int> pi2;

int n, m, h, k;
int board[range][range];  // 맵
int snail[range][range];  // 술래 이동 자취를 위해 달팽이 배열 그림
set<pi2> tree;            // 나무 위치
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct tracer {
  int x;
  int y;
  int d;
  int t;  // snail 배열에서 술래가 있는 칸의 번호
  int s;  // 시계방향 달팽이(0) 인지 반시계 달팽이(1) 인지 나타냄
} tracer;

struct runner {
  int x;
  int y;
  int d;
};

vector<runner> r(10000);

void input() {
  cin >> n >> m >> h >> k;
  // 도망자 위치
  for (int i = 0; i < m; ++i) {
    int x, y, d;
    cin >> x >> y >> d;
    r[i].x = x - 1;
    r[i].y = y - 1;
    r[i].d = d;
  }
  // 나무 위치
  for (int i = 0; i < h; ++i) {
    int x, y;
    cin >> x >> y;
    tree.insert({x - 1, y - 1});
  }
  // 술래 위치
  tracer.x = tracer.y = n / 2;
  tracer.d = 0;
  tracer.t = 1;
}

void draw_one_dir(int *x, int *y, int *e, int dir, int move) {
  for (int i = 0; i < move; ++i) {
    *x = *x + dx[dir];
    *y = *y + dy[dir];
    snail[*x][*y] = (*e)++;
  }
}

void draw() {
  int move = 1, e = 1, x = n / 2, y = n / 2;
  int nx = x, ny = y;
  snail[x][y] = e++;
  while (true) {
    if (move == n) move -= 1;
    draw_one_dir(&nx, &ny, &e, 0, move);
    if (move == n - 1) break;
    draw_one_dir(&nx, &ny, &e, 1, move);
    move += 1;
    draw_one_dir(&nx, &ny, &e, 2, move);
    draw_one_dir(&nx, &ny, &e, 3, move);
    move += 1;
  }
}

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int manhaton(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

// 도망자 이동
// 도망자가 움직일 때 현재 술래와의 거리가 3 이하인 도망자만 움직입니다.
// 도망자의 위치가 (x1, y1), 술래의 위치가 (x2, y2)라 했을 때 두 사람간의 거리는
// |x1 - x2| + |y1 - y2|로 정의됩니다.
/*
1. 현재 바라보고 있는 방향으로 1칸 움직인다 했을 때 격자를 벗어나지 않는 경우
- 움직이려는 칸에 술래가 있는 경우라면 움직이지 않습니다.
- 움직이려는 칸에 술래가 있지 않다면 해당 칸으로 이동합니다. 해당 칸에 나무가
있어도 괜찮습니다.

2. 현재 바라보고 있는 방향으로 1칸 움직인다 했을 때 격자를 벗어나는 경우
- 먼저 방향을 반대로 틀어줍니다. 이후 바라보고 있는 방향으로 1칸 움직인다 헀을
때 해당 위치에 술래가 없다면 1칸 앞으로 이동합니다.
*/
void runner_move() {
  for (int i = 0; i < m; ++i) {
    // 도망자가 이미 잡힌 경우
    if (r[i].x == -1 && r[i].y == -1) continue;
    if (manhaton(r[i].x, r[i].y, tracer.x, tracer.y) <= 3) {
      int dir = r[i].d;
      int nx = r[i].x + dx[dir];
      int ny = r[i].y + dy[dir];
      if (OOB(nx, ny)) {
        dir = (dir + 2) % 4;
        nx = r[i].x + dx[dir];
        ny = r[i].y + dy[dir];
        if (!(tracer.x == nx && tracer.y == ny)) {
          r[i].x = nx;
          r[i].y = ny;
          r[i].d = dir;
        }
      } else {
        if (!(tracer.x == nx && tracer.y == ny)) {
          r[i].x = nx;
          r[i].y = ny;
        }
      }
    }
  }
}

// 술래 이동
// 달팽이로 (n/2, n/2)부터 (0,0)로 이동 후 다시 (n/2, n/2)로 복귀
// 이동할 때 snail 배열을 이용하여 현재 수(t)보다 1 큰 곳으로 이동했다가 n*n
// 만나면 다시 1 작은 곳으로 이동할 것
void tracer_move() {
  if (tracer.t == n * n) tracer.s = 1;
  if (tracer.t == 1) tracer.s = 0;
  // 시계방향 달팽이
  if (tracer.s == 0) {
    for (int dir = 0; dir < 4; ++dir) {
      int nx = tracer.x + dx[dir];
      int ny = tracer.y + dy[dir];
      if (OOB(nx, ny) || tracer.t + 1 != snail[nx][ny]) continue;
      tracer.x = nx;
      tracer.y = ny;
      tracer.t += 1;
      break;
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = tracer.x + dx[dir];
      int ny = tracer.y + dy[dir];
      if (OOB(nx, ny) || tracer.t + 1 != snail[nx][ny]) continue;
      tracer.d = dir;
      break;
    }
  }
  // 반시계 방향 달팽이
  else {
    for (int dir = 0; dir < 4; ++dir) {
      int nx = tracer.x + dx[dir];
      int ny = tracer.y + dy[dir];
      if (OOB(nx, ny) || tracer.t - 1 != snail[nx][ny]) continue;
      tracer.x = nx;
      tracer.y = ny;
      tracer.t -= 1;
      break;
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = tracer.x + dx[dir];
      int ny = tracer.y + dy[dir];
      if (OOB(nx, ny) || tracer.t - 1 != snail[nx][ny]) continue;
      tracer.d = dir;
      break;
    }
  }
}

int catch_runner(int turn) {
  int cnt = 0;
  for (int i = 0; i <= 2; ++i) {
    int nx = tracer.x + i * dx[tracer.d];
    int ny = tracer.y + i * dy[tracer.d];
    if (OOB(nx, ny)) continue;
    if (tree.find({nx, ny}) != tree.end()) continue;  // 나무 제외
    for (int j = 0; j < m; ++j) {
      if (r[j].x == nx && r[j].y == ny) {
        cnt += 1;
        // 도망자 잡힘
        r[j].x = -1;
        r[j].y = -1;
      }
    }
  }
  return cnt * turn;
}

// void print() {
//   // for(int i=0; i<n; ++i){
//   //     for(int j=0; j<n; ++j) cout << snail[i][j] << ' ';
//   //     cout << '\n';
//   // }
//   // cout << "술래 상태(x, y, t, d, s): " << tracer.x << ' ' << tracer.y << '
//   '
//   // << tracer.t << ' ' << tracer.d << ' ' << tracer.s << "\n";
//   for (int i = 0; i < m; ++i) {
//     cout << "도망자" << i << " 상태(x, y, d): " << r[i].x << ' ' << r[i].y
//          << ' ' << r[i].d << '\n';
//   }
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int score = 0;
  input();
  draw();
  for (int turn = 1; turn <= k; ++turn) {
    runner_move();
    tracer_move();
    score += catch_runner(turn);
  }
  cout << score;
  return 0;
}