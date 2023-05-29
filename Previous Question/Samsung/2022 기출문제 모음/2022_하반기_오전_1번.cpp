#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n, m, k;

struct player {
  int x;
  int y;
  int d;
  int ability;
  int gun_point;
  int point;
};

priority_queue<int> gun[range][range];
struct player p[30];

// i번 사람의 이동
// 첫 번째 플레이어부터 순차적으로 본인이 향하고 있는 방향대로 한 칸만큼
// 이동합니다. 만약 해당 방향으로 나갈 때 격자를 벗어나는 경우에는 정반대
// 방향으로 방향을 바꾸어서 1만큼 이동합니다. 방향 d는 0부터 3까지 순서대로 ↑,
// →, ↓, ←을 의미합니다.
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void move(int i) {
  int x = p[i].x;
  int y = p[i].y;
  int d = p[i].d;
  int nx = x + dx[d];
  int ny = y + dy[d];
  if (OOB(nx, ny)) {
    d = (d + 2) % 4;
    nx = x + dx[d];
    ny = y + dy[d];
  }
  p[i].x = nx;
  p[i].y = ny;
  p[i].d = d;
}

// i번 사람의 총 집기
// 만약 이동한 방향에 플레이어가 없다면 해당 칸에 총이 있는지 확인합니다. 총이
// 있는 경우, 해당 플레이어는 총을 획득합니다. 플레이어가 이미 총을 가지고 있는
// 경우에는 놓여있는 총들과 플레이어가 가지고 있는 총 가운데 공격력이 더 쎈 총을
// 획득하고, 나머지 총들은 해당 격자에 둡니다.
void put_gun(int i) {
  int x = p[i].x;
  int y = p[i].y;
  int gp = p[i].gun_point;
  for (int j = 0; j < m; ++j) {
    if (i == j) continue;
    if (p[j].x == x && p[j].y == y) return;
  }
  if (gun[x][y].empty()) return;
  if (gun[x][y].top() > gp) {
    p[i].gun_point = gun[x][y].top();
    gun[x][y].pop();
    if (gp != 0) gun[x][y].push(gp);
  }
}

// 싸우고 나서 루저 처리
// 진 플레이어는 본인이 가지고 있는 총을 해당 격자에 내려놓고, 해당 플레이어가
// 원래 가지고 있던 방향대로 한 칸 이동합니다. 만약 이동하려는 칸에 다른
// 플레이어가 있거나 격자 범위 밖인 경우에는 오른쪽으로 90도씩 회전하여 빈 칸이
// 보이는 순간 이동합니다. 만약 해당 칸에 총이 있다면, 해당 플레이어는 가장
// 공격력이 높은 총을 획득하고 나머지 총들은 해당 격자에 내려 놓습니다.
void loser(int i) {
  int x = p[i].x;
  int y = p[i].y;
  int d = p[i].d;
  int nx = x + dx[d];
  int ny = y + dy[d];
  int gp = p[i].gun_point;
  if (gp != 0) {
    gun[x][y].push(gp);
    p[i].gun_point = 0;
  }
  while (true) {
    bool is_exist = false;
    for (int j = 0; j < m; ++j) {
      if (i == j) continue;
      if (p[j].x == nx && p[j].y == ny) is_exist = true;
    }
    if (!OOB(nx, ny) && !is_exist) break;
    d = (d + 1) % 4;
    nx = x + dx[d];
    ny = y + dy[d];
  }
  p[i].x = nx;
  p[i].y = ny;
  p[i].d = d;
  put_gun(i);
}

// 싸우고 나서 위너 처리
// 이긴 플레이어는 승리한 칸에 떨어져 있는 총들과 원래 들고 있던 총 중 가장
// 공격력이 높은 총을 획득하고, 나머지 총들은 해당 격자에 내려 놓습니다.
void winner(int i) { put_gun(i); }

// 격자에서 싸움
// 만약 이동한 방향에 플레이어가 있는 경우에는 두 플레이어가 싸우게 됩니다. 해당
// 플레이어의 초기 능력치와 가지고 있는 총의 공격력의 합을 비교하여 더 큰
// 플레이어가 이기게 됩니다. 만일 이 수치가 같은 경우에는 플레이어의 초기
// 능력치가 높은 플레이어가 승리하게 됩니다. 이긴 플레이어는 각 플레이어의 초기
// 능력치와 가지고 있는 총의 공격력의 합의 차이만큼을 포인트로 획득하게 됩니다.
// 승자 결정하는 함수
void fight(int i, int j) {
  // cout << "싸움 " << i << ' ' << j << '\n';
  // cout << i << ' ' << j << '\n';
  int ia = p[i].gun_point + p[i].ability;
  int ja = p[j].gun_point + p[j].ability;
  if (ia == ja) {
    if (p[i].ability > p[j].ability) {
      loser(j);
      winner(i);
      p[i].point += ia - ja;
    } else {
      loser(i);
      winner(j);
      p[j].point += ja - ia;
    }
  } else if (ia > ja) {
    loser(j);
    winner(i);
    p[i].point += ia - ja;
  } else {
    loser(i);
    winner(j);
    p[j].point += ja - ia;
  }
}

void input() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int g;
      cin >> g;
      if (g != 0) gun[i][j].push(g);
    }
  for (int i = 0; i < m; ++i) {
    int x, y, d, s;
    cin >> x >> y >> d >> s;
    p[i].x = x - 1;
    p[i].y = y - 1;
    p[i].d = d;
    p[i].ability = s;
  }
}

void print_status() {
  for (int i = 0; i < m; ++i) {
    cout << i << "번 사람의 상태\n";
    cout << p[i].x << ' ' << p[i].y << ' ' << p[i].d << ' ' << p[i].ability
         << ' ' << p[i].gun_point << ' ' << p[i].point << '\n';
  }
}

void print_guns() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << gun[i][j].size() << ' ';
    }
    cout << '\n';
  }
}

void simulation() {
  for (int i = 0; i < m; ++i) {
    move(i);
    put_gun(i);
    for (int j = 0; j < m; ++j) {
      if (i == j) continue;
      if (p[i].x == p[j].x && p[i].y == p[j].y) fight(i, j);
    }
  }
}

int main() {
  // 여기에 코드를 작성해주세요.
  input();
  while (k--) {
    simulation();
    // print_status();
    // print_guns();
    // cout << '\n';
  }
  for (int i = 0; i < m; ++i) cout << p[i].point << ' ';
  return 0;
}