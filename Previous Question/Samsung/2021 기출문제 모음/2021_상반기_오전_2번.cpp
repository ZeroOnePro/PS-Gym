#include <bits/stdc++.h>

#define EMPTY -2
#define STONE -1
#define RED 0

using namespace std;

typedef pair<int, int> pi2;

const int range = 25;

int n, m, score;
int board[range][range];
bool vis[range][range];
vector<pair<vector<pi2>, vector<pi2>>> boom_group;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool compare(pair<vector<pi2>, vector<pi2>> a,
             pair<vector<pi2>, vector<pi2>> b) {
  if (a.first.size() + a.second.size() == b.first.size() + b.second.size()) {
    if (a.first.size() == b.first.size()) {
      if (a.second[0].first == b.second[0].first)
        return a.second[0].second < b.second[0].second;
      return a.second[0].first > b.second[0].first;
    }
    return a.first.size() < b.first.size();
  }
  return a.first.size() + a.second.size() > b.first.size() + b.second.size();
}

bool c_compare(pi2 a, pi2 b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}

/**
 * @brief input
 *
 */
void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
}

/**
 * @brief 가장 큰 폭탄 묶음 찾기
 *
 */
void bfs(int i, int j) {
  int bn = board[i][j];
  vector<pi2> boom, red_boom;
  queue<pi2> q;
  q.push({i, j});
  vis[i][j] = true;
  boom.push_back({i, j});
  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny]) continue;
      if (board[nx][ny] == STONE || board[nx][ny] == EMPTY ||
          board[nx][ny] > RED && board[nx][ny] != bn)
        continue;
      if (board[nx][ny] == RED)
        red_boom.push_back({nx, ny});
      else
        boom.push_back({nx, ny});
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
  for (pair<int, int> r : red_boom) vis[r.first][r.second] = false;
  sort(boom.begin(), boom.end(), c_compare);
  boom_group.push_back({red_boom, boom});
}

void find_boom_group() {
  int group = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (board[i][j] >= 1 && !vis[i][j]) {
        bfs(i, j);
        group += 1;
      }
  sort(boom_group.begin(), boom_group.end(), compare);
}

/**
 * @brief 폭탄 그룹 터트리고 점수에 추가
 *
 */
void blast_boom_group() {
  pair<vector<pi2>, vector<pi2>> p = boom_group[0];
  for (pair<int, int> c : p.first) {
    int x, y;
    tie(x, y) = c;
    board[x][y] = EMPTY;
  }
  for (pair<int, int> c : p.second) {
    int x, y;
    tie(x, y) = c;
    board[x][y] = EMPTY;
  }
  score +=
      (p.first.size() + p.second.size()) * (p.first.size() + p.second.size());
}

/**
 * @brief 중력 적용
 *
 */
void apply_gravity() {
  int tmp[range][range];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) tmp[i][j] = EMPTY;

  for (int j = 0; j < n; j++) {
    int last_idx = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (board[i][j] == EMPTY) continue;
      if (board[i][j] == STONE) last_idx = i;
      tmp[last_idx--][j] = board[i][j];
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) board[i][j] = tmp[i][j];
}

/**
 * @brief 반시계 90도 회전
 *
 */
void rotate() {
  int tmp[range][range];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) tmp[i][j] = EMPTY;

  for (int j = n - 1; j >= 0; j--)
    for (int i = 0; i < n; i++) tmp[n - 1 - j][i] = board[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) board[i][j] = tmp[i][j];
}

/**
 * @brief board에 폭탄 남아있는지 검사
 *
 * @return bool
 */
bool check_remain() {
  int cnt = 0;
  for (pair<vector<pi2>, vector<pi2>> bg : boom_group)
    if (bg.first.size() + bg.second.size() >= 2) return true;
  return false;
}

/**
 * @brief 라운드가 끝나고 사용했던 것들 초기화
 *
 */
void init() {
  for (int i = 0; i < n; ++i) fill(vis[i], vis[i] + n, false);
  boom_group.clear();
}

/**
 * @brief 디버깅용 프린트
 *
 */
void print() {
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  while (true) {
    find_boom_group();
    if (!check_remain()) break;
    blast_boom_group();
    apply_gravity();
    rotate();
    apply_gravity();
    init();
  }
  cout << score;
  return 0;
}