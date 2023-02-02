#include <bits/stdc++.h>

using namespace std;

const int range = 15;

enum { WHITE, RED, BLUE };

int n, k, turn = 1;

// 말의 정보
struct h {
  int num;
  int x;
  int y;
  int dir;
};

vector<h> horse(range);         // 말들의 위치 및 방향을 관리
int board[range][range];        // 체스판
list<int> order[range][range];  // 각 격자에서 말들의 번호를 저장

void print() {
  cout << '\n';
  cout << "turn: " << turn << '\n';
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cout << "[" << i + 1 << "]"
           << "[" << j + 1 << "]: ";
      for (int e : order[i][j]) cout << e + 1 << ", ";
      cout << '\n';
    }
}

void input() {
  cin >> n >> k;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];

  for (int i = 0; i < k; ++i) {
    cin >> horse[i].x >> horse[i].y >> horse[i].dir;
    horse[i].num = i;
    horse[i].x--;
    horse[i].y--;
    horse[i].dir--;
    order[horse[i].x][horse[i].y].push_back(i);
  }
}

// 순서 => 우좌상하
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int flip[] = {1, 0, 3, 2};  // 방향을 반대로 바꿨을 때 번호

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

int concat(int x, int y, int nx, int ny, int i, bool is_red) {
  auto iter = find(order[x][y].begin(), order[x][y].end(), i);
  list<int> tmp(iter, order[x][y].end());
  for (int e : tmp) {
    horse[e].x = nx;
    horse[e].y = ny;
  }
  if (is_red) reverse(tmp.begin(), tmp.end());
  order[nx][ny].splice(order[nx][ny].end(), tmp);
  order[x][y].erase(iter, order[x][y].end());
  return order[nx][ny].size();
}

// i번 째 말이 하양, 빨강, 파랑 칸으로 갔을 때 행동 정의
int move(int i) {
  int cnt = 0;
  auto [num, x, y, dir] = horse[i];
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  if (OOB(nx, ny) || board[nx][ny] == BLUE) {
    horse[i].dir = flip[dir];
    nx = x + dx[flip[dir]];
    ny = y + dy[flip[dir]];
    if (OOB(nx, ny) || board[nx][ny] == BLUE) return cnt;
  }
  cnt = concat(x, y, nx, ny, num, board[nx][ny] == RED);
  return cnt;
}

// 게임을 진행한다
bool game() {
  // 하나라도 true면 게임 끝
  bool res = false;
  for (int i = 0; i < k; ++i) res |= (move(i) >= 4);
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  while (true) {
    bool res = game();
    if (res) {
      cout << turn;
      break;
    }
    turn += 1;
    if (turn > 1000) {
      cout << -1;
      break;
    }
  }
  return 0;
}