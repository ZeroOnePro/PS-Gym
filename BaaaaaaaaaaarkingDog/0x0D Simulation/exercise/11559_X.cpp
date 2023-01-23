#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int range = 6;

string board[range * 2 + 5];

int boom_case;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {
  return x < 0 || y < 0 || x >= 2 * range || y >= range;
}

// 푸요 4개가 상하좌우로 연결되어있는지 검사
// 세 번의 턴 내에서 같은 게 시작점과 같은게 세 개나와야함
// 마킹해놨다가 .으로 변경
int bfs(int x, int y) {
  int boomed = 0;
  int cnt = 0;
  queue<pii> q;
  queue<pii> mark;
  int dist[range * 2][range];
  for (int i = 0; i < 2 * range; ++i) fill(dist[i], dist[i] + range, -1);
  int st_x = x, st_y = y;
  q.push({x, y});
  dist[x][y] = 0;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    if (dist[x][y] > 3) break;  // 이거 해도 괜찮아? 응 괜찮아
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
      // 검사 로직 틀림 => 왜 틀렸는지 분석하기
      // 영역의 너비 검사할 때 어떻게 했는지 까먹었냐?? 나 취업할 수 있을까?ㅠㅠ
      if (board[nx][ny] != board[st_x][st_y]) continue;
      // 터지는 거 마킹해줘야 함, 좌표 저장해놨다가 .으로 변경
      mark.push({nx, ny});
      cnt += 1;
      q.push({nx, ny});
      dist[nx][ny] = dist[x][y] + 1;
    }
  }
  if (cnt >= 3) {
    board[st_x][st_y] = '.';
    while (!mark.empty()) {
      tie(x, y) = mark.front();
      mark.pop();
      board[x][y] = '.';
    }
    boomed += 1;
  }
  return boomed;
}

// 터질 수 있는 푸요 그룹있는지 검사
// 보드 검사하면서 푸요 발견되면 시작점으로 설정
// 꽉 차있는 경우도 있을 수 있으니까 위에서부터 검사해도 굳이 상관은 없겠다
// 모든 탐색을 돌렸을 때 터지는 게 하나도 없으면 false 리턴해서 끝내줘야한다
bool check() {
  bool is_boom = false;
  for (int i = range * 2 - 1; i >= 0; --i)
    for (int j = 0; j < range; ++j)
      if (board[i][j] != '.')
        if (bfs(i, j) > 0) is_boom = true;
  if (is_boom) boom_case += 1;
  return is_boom;
}

// 터진 후 재배치
// 한 열마다 제일 밑 행부터 검사하여 .이 나오면 제일 처음만난 뿌요와 swap
void reloc() {
  for (int j = 0; j < range; ++j)
    for (int i = 2 * range - 1; i >= 0; --i) {
      if (board[i][j] == '.')
        for (int k = i - 1; k >= 0; --k)
          if (board[k][j] != '.') {
            swap(board[i][j], board[k][j]);
            break;
          }
    }
}

void print_board() {
  cout << '\n';
  for (int i = 0; i < range * 2; ++i) {
    for (int j = 0; j < range; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < 2 * range; ++i) cin >> board[i];
  while (check()) {
    reloc();
    // print_board();
  }
  cout << boom_case;
  return 0;
}