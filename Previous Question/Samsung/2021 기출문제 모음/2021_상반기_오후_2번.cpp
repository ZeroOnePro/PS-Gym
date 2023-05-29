#include <bits/stdc++.h>

using namespace std;

const int range = 30;

int n, m, p, score;

int board[range][range];
map<int, pair<int, int>> attack;
vector<pair<int, int>> spiral_points;

// 디버깅용 출력
void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}

// 달팽이 방향으로 탐색
void search_snail(int x, int y) {
  // 좌 하 우 상
  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};

  int dir = 0, move = 1;

  while (x || y) {
    // move_num 만큼 이동합니다.
    for (int i = 0; i < move; i++) {
      x += dx[dir];
      y += dy[dir];
      spiral_points.push_back(make_pair(x, y));
      if (x == 0 && y == 0) break;
    }

    dir = (dir + 1) % 4;
    // 왼쪽이나 오른쪽으로 방향을 틀 경우 이동 횟수 증가
    if (dir == 0 || dir == 2) move += 1;
  }
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
  for (int i = 1; i <= m; ++i) {
    int d, p;
    cin >> d >> p;
    attack[i] = make_pair(d, p);
  }
}

/*
1. 몬스터 당기기

비어있는 공간만큼 몬스터는 앞으로 이동하여 빈 공간을 채웁니다.
*/

void pull_monster() {
  int idx = 0;
  int tmp[range][range];
  for (int i = 0; i < n; ++i) fill(tmp[i], tmp[i] + n, 0);
  for (auto sp : spiral_points) {
    int sx, sy, tx, ty;
    tie(sx, sy) = sp;
    if (board[sx][sy]) {
      tie(tx, ty) = spiral_points[idx];
      tmp[tx][ty] = board[sx][sy];
      idx += 1;
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) board[i][j] = tmp[i][j];
}

/*
2. 몬스터 공격

플레이어는 상하좌우 방향 중 주어진 공격 칸 수만큼 몬스터를 공격하여 없앨 수
있습니다.
*/
void attack_monster(int turn) {
  // d는 0번부터 3번까지 각각 → ↓ ← ↑으로 주어집니다.(시계 방향)
  // 1 ≤ p ≤ floor(n/2)
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  auto [d, p] = attack[turn];
  for (int i = 1; i <= p; ++i) {
    int nx = n / 2 + dx[d] * i;
    int ny = n / 2 + dy[d] * i;
    score += board[nx][ny];
    board[nx][ny] = 0;
  }
  pull_monster();
}

/*
3. 몬스터 제거

이때 몬스터의 종류가 4번 이상 반복하여 나오면 해당 몬스터 또한 삭제됩니다.
해당 몬스터들은 동시에 사라집니다

삭제된 이후에는 몬스터들을 앞으로 당겨주고, 4번 이상 나오는 몬스터가 있을 경우
또 삭제를 해줍니다. 4번 이상 나오는 몬스터가 없을 때까지 반복해줍니다.

문제를 잘못 이해하신 것 같습니다. 현재 시점에서 4번이상 등장하는 몬스터들을 전부
동시에 없애준 뒤, 댕겨준 이후에 다시 4번 이상 등장하는 몬스터들을 전부 동시에
없애주는 것을 반복해주셔야 합니다.

지금 말씀해주신 예시는 4번 이상 등장하는 몬스터가 보이는 순간 그 그룹만 없애고,
당긴 뒤, 다시 4번 이상 등장하는 몬스터를 찾아 그 그룹만 없애는 것 같네요 :)
*/
void remove_monster() {
  while (true) {
    bool is_remain = false;
    int st = 0, en = spiral_points.size() - 1;
    while (st <= en) {
      int x, y;
      vector<pair<int, int>> cp;
      tie(x, y) = spiral_points[st];
      int elem = board[x][y];
      int cur = st + 1;
      if (elem > 0) {
        cp.push_back({x, y});
        while (cur <= en) {
          int nx, ny;
          tie(nx, ny) = spiral_points[cur];
          if (elem == board[nx][ny]) {
            cp.push_back({nx, ny});
            cur += 1;
          } else
            break;
        }
        if (cp.size() >= 4) {
          is_remain = true;
          score += board[x][y] * cp.size();
          for (pair<int, int> p : cp) {
            tie(x, y) = p;
            board[x][y] = 0;
          }
        }
      }
      st = cur;
    }
    if (!is_remain) break;
    pull_monster();
  }
}

/*
4. 몬스터 재배치

삭제가 끝난 다음에는 몬스터를 차례대로 나열했을 때 같은 숫자끼리 짝을
지어줍니다. 이후 각각의 짝을 (총 개수, 숫자의 크기)로 바꾸어서 다시 미로
속에 집어넣습니다.

만약 새로 생긴 배열이 원래 격자의 범위를 넘는다면 나머지 배열은 무시합니다.

*/
void relocate_monster() {
  int st = 0, en = spiral_points.size() - 1;
  int x, y;
  vector<int> tmp;
  tie(x, y) = spiral_points[st];
  int elem = board[x][y];
  while (elem != 0) {
    int cur = st + 1, cnt = 1;
    while (cur <= en) {
      int nx, ny;
      tie(nx, ny) = spiral_points[cur];
      if (elem == board[nx][ny]) {
        cur += 1;
        cnt += 1;
      } else
        break;
    }
    tmp.push_back(cnt);
    tmp.push_back(elem);
    tie(x, y) = spiral_points[cur];
    elem = board[x][y];
    st = cur;
  }
  int index = 0;
  for (int i : tmp) {
    tie(x, y) = spiral_points[index];
    board[x][y] = i;
    index += 1;
    if (index >= spiral_points.size()) break;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  search_snail(n / 2, n / 2);
  for (int turn = 1; turn <= m; ++turn) {
    attack_monster(turn);
    remove_monster();
    relocate_monster();
  }
  cout << score;
  return 0;
}