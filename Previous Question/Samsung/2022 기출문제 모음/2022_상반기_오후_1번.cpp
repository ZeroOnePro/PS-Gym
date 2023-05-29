#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n, m, k;
int board[range][range];
bool vis[range][range];

// head의 이동위치만 정해주면 그 다음 사람부터는 이전 사람의 좌표를 대입해주면
// 이동한 것이 됨 이동 방향 전환
struct human {
  int x;  // x 좌표
  int y;  // y 좌표
  int n;  // 번호(머리인지 꼬리인지 판단)
};

vector<human> t[6];
int team[6];  // 팀이 획득한 점수

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// 팀 정하기
void dfs(int x, int y, int team) {
  vis[x][y] = true;
  if (board[x][y] == 4 || board[x][y] == 0) return;
  if (0 < board[x][y] && board[x][y] < 4)
    t[team].push_back({x, y, board[x][y]});
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0 ||
        board[x][y] == 1 && board[nx][ny] != 2)
      continue;
    dfs(nx, ny, team);
  }
}

void input() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
}

// 맵에서 팀 찾기
void find_team() {
  int team = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (board[i][j] == 1 && !vis[i][j]) dfs(i, j, team++);
}

// 팀 이동
// head가 갈 수 있는 위치 찾는다
// 상하좌우 살펴보고 맵의 빈 칸이면 간다
// head가 갈 위치가 정해지면 2번째 팀원부터 이전 원소의 좌표를 받는다
// board의 원소도 변경해줘야함
void move() {
  for (int i = 1; i <= m; ++i) {
    int x = t[i][0].x;
    int y = t[i][0].y;
    int nx = x;
    int ny = y;
    // 갈 수 있는 칸은 항상 하나로 정해진다, 예외는 없다
    for (int dir = 0; dir < 4; ++dir) {
      nx = x + dx[dir];
      ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (board[nx][ny] == 4 || board[nx][ny] == 3) break;
    }
    // 팀원들 한 칸씩 전진
    for (int j = t[i].size() - 1; j > 0; --j) {
      if (j == t[i].size() - 1) {
        board[t[i][j].x][t[i][j].y] = 4;
      }
      t[i][j].x = t[i][j - 1].x;
      t[i][j].y = t[i][j - 1].y;
      board[t[i][j].x][t[i][j].y] = t[i][j].n;
    }
    // 헤드 좌표 변경
    t[i][0].x = nx;
    t[i][0].y = ny;
    board[nx][ny] = 1;
  }
}

// 공에 맞은 팀원이 있는 경우 헤드와 꼬리 교체
void swap_head_tail(int i) {
  int tail = t[i].size() - 1;
  reverse(t[i].begin(), t[i].end());
  t[i][0].n = 1;
  board[t[i][0].x][t[i][0].y] = 1;
  t[i][tail].n = 3;
  board[t[i][tail].x][t[i][tail].y] = 3;
}

// 공 던지기
// 4n까지 모듈라로 돈다
// 같은 라인에 같은 팀 여려명하고 다른 팀인원 있음
// 만난애들 좌표 모두 파악하고 공 시작 만났을 때의 거리 파악해서 제일 가까운애만
// 남기기
void throw_ball(int round) {
  round = round % (4 * n);
  if (round == 0) round = 4 * n;
  if (round <= n) {
    round = round - 1;
    int mn = n, hit = -1, s = -1;
    for (int i = 1; i <= m; ++i) {
      // 행은 round이고 열은 제일 작은거 찾기
      for (int j = 0; j < t[i].size(); ++j) {
        if (t[i][j].x == round && mn > t[i][j].y) {
          s = i;
          mn = t[i][j].y;
          hit = j;
        }
      }
    }
    if (mn != n && hit != -1 && s != -1) {
      team[s] += (hit + 1) * (hit + 1);
      swap_head_tail(s);
    }
  } else if (round <= 2 * n) {
    round = round - 1;
    // 열이 round - n인 것 중 row가 제일 큰 거 찾기
    int mx = -1, hit = -1, s = -1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < t[i].size(); ++j) {
        if (t[i][j].y == round - n && mx < t[i][j].x) {
          s = i;
          mx = t[i][j].x;
          hit = j;
        }
      }
    }
    if (mx != -1 && hit != -1 && s != -1) {
      team[s] += (hit + 1) * (hit + 1);
      swap_head_tail(s);
    }
  } else if (round <= 3 * n) {
    round = round - 1;
    // 행이 3 * n - round - 1인 것 중 열이 제일 큰 거 찾기
    int mx = -1, hit = -1, s = -1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < t[i].size(); ++j) {
        if (t[i][j].x == 3 * n - round - 1 && mx < t[i][j].y) {
          s = i;
          mx = t[i][j].y;
          hit = j;
        }
      }
    }
    if (mx != -1 && hit != -1 && s != -1) {
      team[s] += (hit + 1) * (hit + 1);
      swap_head_tail(s);
    }
  } else {
    round = round - 1;
    // 열이 4 * round - n인 것 중 행이 제일 작은 거 찾기
    int mn = n, hit = -1, s = -1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < t[i].size(); ++j) {
        if (t[i][j].y == 4 * n - round - 1 && mn > t[i][j].x) {
          s = i;
          mn = t[i][j].x;
          hit = j;
        }
      }
    }
    if (mn != n && hit != -1 && s != -1) {
      team[s] += (hit + 1) * (hit + 1);
      swap_head_tail(s);
    }
  }
}

int main() {
  input();
  find_team();
  for (int i = 1; i <= k; ++i) {
    move();
    throw_ball(i);
  }
  int sum = 0;
  for (int i = 1; i <= m; ++i) sum += team[i];
  cout << sum;
  return 0;
}