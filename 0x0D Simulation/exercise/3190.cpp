#include <bits/stdc++.h>

using namespace std;

const int range = 105;

int n, k, l, x, y;

enum { APPLE = 1 };

int board[range][range];
bool vis[range][range];
// (경과 시간, 전환할 방향)
map<int, char> path;
list<pair<int, int>> snake;

// 뱀이 어딜 보고있느냐에 따라 상하좌우가 각각 L과 D가 될 수 있다
int cur_time = 0;    // 게임 진행 시각
char cur_dir = 'R';  // 현재 뱀이 보고 있는 방향
// UDLR
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 방향 결정
// 입력으로 받은 변환 정보에 따라 cur_time이 해당 시간이 되었을 때 방향 변환
// 아니라면 현재 방향 유지
// dx, dy의 인덱스 반환
// 각 방향에 번호를 매겨서 서큘러 관계 형성하게 만들면 모듈러 이용할 거 같은데
// 나중에 리팩토링 해보기
int decise_dir(int t) {
  // 전환시키기
  if (path.find(t) != path.end()) {
    if (cur_dir == 'R') {
      if (path[t] == 'L') {
        cur_dir = 'U';
        return 0;
      } else {
        cur_dir = 'D';
        return 1;
      }
    } else if (cur_dir == 'L') {
      if (path[t] == 'L') {
        cur_dir = 'D';
        return 1;
      } else {
        cur_dir = 'U';
        return 0;
      }
    } else if (cur_dir == 'D') {
      if (path[t] == 'L') {
        cur_dir = 'R';
        return 3;
      } else {
        cur_dir = 'L';
        return 2;
      }
    } else {
      if (path[t] == 'L') {
        cur_dir = 'L';
        return 2;
      } else {
        cur_dir = 'R';
        return 3;
      }
    }
  }
  // 현재 방향 유지
  else {
    if (cur_dir == 'R')
      return 3;
    else if (cur_dir == 'L')
      return 2;
    else if (cur_dir == 'D')
      return 1;
    else
      return 0;
  }
}

// 뱀위 자취를 변경하는 함수
// 뱀이 위치하는 칸을 링크드 리스트로 관리
// 사과 먹으면 꼬리 안자르면 됨
// 사과 없으면 꼬리 자르고 머리 추가
// 꼬리 -> 몸통 1 -> ... -> 머리 순
void decise_snake(int nx, int ny) {
  snake.push_back({nx, ny});  // 머리추가
  if (board[nx][ny] != APPLE) {
    auto [tx, ty] = snake.front();
    vis[tx][ty] = false;
    snake.pop_front();  // 꼬리자르기
  } else
    board[nx][ny] = 0;
  return;
}

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

// 뱀의 이동
// 뱀위 머리(x, y)가 다음 좌표로 이동
// 방향전환 후 이동했을 때 자기자신과 만나거나 벽을 만나면 게임 종료
bool move(int t) {
  int dir = decise_dir(t);
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  if (OOB(nx, ny) || vis[nx][ny]) return false;
  vis[nx][ny] = true;
  decise_snake(nx, ny);
  x = nx;
  y = ny;
  return true;
}

void print() {
  cout << '\n';
  cout << "time: " << cur_time << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vis[i][j])
        cout << 2 << ' ';
      else
        cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int r, c;
    cin >> r >> c;
    // 1-indexed로 주어진다
    board[--r][--c] = APPLE;
  }
  cin >> l;
  for (int i = 0; i < l; ++i) {
    int x;
    char dir;
    cin >> x >> dir;
    if (dir == 'D') dir = 'R';
    path[x] = dir;
  }
  vis[0][0] = true;
  snake.push_back({0, 0});
  while (true) {
    if (!move(cur_time)) break;
    cur_time += 1;
  }
  cout << cur_time + 1;  // 부딪혀서 소멸하는 시간 추가
  return 0;
}