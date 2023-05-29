#include <bits/stdc++.h>

using namespace std;

const int range = 20;

int n, m;

int board[range][range];
map<int, pair<int, int>> rule;
vector<pair<int, int>> nutrient;

bool OOB(int x, int y) { return x < 0 || x >= n | y < 0 || y >= n; }

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
  for (int i = 1; i <= m; ++i) {
    int d, p;
    cin >> d >> p;
    rule[i] = {d - 1, p};
  }
  for (int i = n - 2; i < n; ++i)
    for (int j = 0; j < 2; ++j) nutrient.push_back({i, j});
}

/**
 * 영양제의 이동
 * 이동 방향의 경우 1번부터 8번까지 → ↗ ↑ ↖ ← ↙ ↓ ↘으로 주어지며 이동 칸 수만큼
 * 특수 영양제가 이동하게 됩니다. 격자의 모든 행,열은 각각 끝과 끝이 연결되어
 * 있습니다. 즉 격자 바깥으로 나가면 마치 지구가 둥근것처럼 반대편으로
 * 돌아옵니다. 만약 n번 열에서 오른쪽에서 이동하는 경우에는 1번 열으로 이동하게
 * 됩니다.
 */
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void move_nutrient(int turn) {
  vector<pair<int, int>> tmp;
  for (pair<int, int> nu : nutrient) {
    int x, y, d, p;
    tie(x, y) = nu;
    tie(d, p) = rule[turn];
    int nx = (x + dx[d] * p + n * p) % n;
    int ny = (y + dy[d] * p + n * p) % n;
    tmp.push_back({nx, ny});
  }
  nutrient = tmp;
}

/**
 * 나무 성장
 * 특수 영양제를 투입한 리브로수의 대각선으로 인접한 방향에 높이가 1 이상인
 * 리브로수가 있는 만큼 높이가 더 성장합니다. 대각선으로 인접한 방향이 격자를
 * 벗어나는 경우에는 세지 않습니다.
 *
 * 동시에 자라는 게 아니라 먼저 자라는 나무가 영향을 줘도 되나? => 서로
 * 붙어있어도 무조건 1씩 성장하기 때문에 영향을 준다
 */

void grow_tree() {
  int ddx[] = {-1, 1, 1, -1};
  int ddy[] = {-1, -1, 1, 1};
  for (pair<int, int> nu : nutrient) {
    int x, y;
    tie(x, y) = nu;
    board[x][y] += 1;
  }
  for (pair<int, int> nu : nutrient) {
    int x, y;
    tie(x, y) = nu;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + ddx[dir];
      int ny = y + ddy[dir];
      if (OOB(nx, ny)) continue;
      if (board[nx][ny] > 0) board[x][y] += 1;
    }
  }
}

/**
 * 나무 자르기
 * 높이가 2 이상인 리브로수는 높이 2를 베어서 잘라낸 리브로수로 특수 영양제를
 * 사고, 해당 위치에 특수 영양제를 올려둡니다.
 */
void cut_tree() {
  bool vis[range][range];
  vector<pair<int, int>> tmp;
  for (int i = 0; i < range; ++i) fill(vis[i], vis[i] + range, false);

  for (pair<int, int> nu : nutrient) {
    int x, y;
    tie(x, y) = nu;
    vis[x][y] = true;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (board[i][j] >= 2 && !vis[i][j]) {
        board[i][j] -= 2;
        tmp.push_back({i, j});
      }
  nutrient = tmp;
}

/**
 * 남은 나무 수 구하기
 */
int clac_tree() {
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cnt += board[i][j];
  return cnt;
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  for (int turn = 1; turn <= m; ++turn) {
    move_nutrient(turn);
    grow_tree();
    cut_tree();
  }
  cout << clac_tree();
  return 0;
}