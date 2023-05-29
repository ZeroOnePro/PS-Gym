#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n, m;

struct dice {
  int x;
  int y;
  int dir;
  int up;     // 주사위 윗면
  int down;   // 주사위 아래면
  int front;  // 주사위 앞면
  int back;   // 주사위 뒷면
  int left;   // 주사위 왼쪽 면
  int right;  // 주사위 오른쪽 면
} dice;

int board[range][range];

// 시계방향으로 우하좌상
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 구역을 파악한 다음 각 좌표에서 몇 점을 얻을 수 있는지 구하는 함수
bool vis[range][range];
int score[range][range];
bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void bfs(int x, int y) {
  int an = board[x][y];
  queue<pair<int, int>> q;
  vector<pair<int, int>> c;
  c.push_back({x, y});
  q.push({x, y});
  vis[x][y] = true;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] != an) continue;
      c.push_back({nx, ny});
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
  for (auto p : c) {
    tie(x, y) = p;
    score[x][y] = c.size() * board[x][y];
  }
}

// 주사위 굴리는 함수
void roll_dice(int d) {
  struct dice nd = dice;
  // 오른쪽 굴리기 => 우 방향
  if (d == 0) {
    nd.right = dice.up;
    nd.left = dice.down;
    nd.up = dice.left;
    nd.down = dice.right;
    nd.front = dice.front;
    nd.back = dice.back;
  }
  // 앞으로 굴리기 => 하 방향
  else if (d == 1) {
    nd.front = dice.up;
    nd.back = dice.down;
    nd.left = dice.left;
    nd.right = dice.right;
    nd.down = dice.front;
    nd.up = dice.back;
  }
  // 왼쪽으로 굴리기 => 좌 방향
  else if (d == 2) {
    nd.left = dice.up;
    nd.right = dice.down;
    nd.down = dice.left;
    nd.up = dice.right;
    nd.front = dice.front;
    nd.back = dice.back;
  }
  // 뒤로 굴리기 => 상 방향
  else {
    nd.back = dice.up;
    nd.front = dice.down;
    nd.left = dice.left;
    nd.right = dice.right;
    nd.up = dice.front;
    nd.down = dice.back;
  }
  dice = nd;
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
  dice.x = 0;
  dice.y = 0;
  dice.dir = 0;
  dice.up = 1;
  dice.down = 6;
  dice.front = 2;
  dice.back = 5;
  dice.left = 4;
  dice.right = 3;
}

// 주사위 이동
/*
 1. 주사위의 아랫면이 보드의 해당 칸에 있는 숫자보다 크면 현재 진행방향에서 90'
 시계방향으로 회전하여 다시 이동을 진행하게 되고,
 2. 주사위의 아랫면의 숫자가 더 작다면 현재 진행방향에서 90' 반시계방향으로
 회전하게 되며,
 3. 동일하다면 현재 방향으로 계속 진행하게 됩니다.
 4. 격자판을 벗어나게 된다면, 반사되어 방향이 반대로 바뀌게 된 뒤 한 칸 움직이게
 됩니다.
*/
int move(int s, int turn) {
  int x = dice.x;
  int y = dice.y;
  int d = dice.dir;
  if (turn > 1) {
    if (dice.down > board[x][y])
      d = (dice.dir + 1) % 4;
    else if (dice.down < board[x][y]) {
      d = d - 1;
      if (d == -1) d = 3;
    } else
      d = dice.dir;
  }
  int nx = x + dx[d];
  int ny = y + dy[d];
  if (OOB(nx, ny)) {
    d = (d + 2) % 4;
    nx = x + dx[d];
    ny = y + dy[d];
  }
  dice.x = nx;
  dice.y = ny;
  roll_dice(d);
  dice.dir = d;
  return score[nx][ny];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int s = 0;
  input();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (!vis[i][j]) bfs(i, j);
  for (int i = 1; i <= m; ++i) s += move(s, i);
  cout << s;
  return 0;
}