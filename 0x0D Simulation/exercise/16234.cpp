#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int range = 55;

int n, l, r, day;

int board[range][range];
int area[range][range];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

// bfs
// 인구이동이 발생하지 않으면 끝내기
bool bfs(int x, int y, int an) {
  bool is_possible = false;
  queue<pii> q;
  q.push({x, y});
  area[x][y] = an;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || area[nx][ny] == an) continue;
      int diff = abs(board[nx][ny] - board[x][y]);
      if (diff < l || diff > r) continue;
      // 재방문 노드를 방문할 경우 새로운 연합이 만들어진다는
      // 의미이므로 커팅하면 안된다
      q.push({nx, ny});
      area[nx][ny] = an;
      is_possible = true;
    }
  }
  return is_possible;
}

// 인구 이동
// 각 영역별(1부터 시작하기)로 연합을 만들어주고 숫자 변경
// 연합이 모두 발견되야 계산이 가능하므로 탐색을 마치고 시뮬레이션 수행해야한다
// 영역번호를 키로하고 값을 좌표로해서 평균계산한 후 반영해주기
void move() {
  map<int, vector<pii>> areas;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) areas[area[i][j]].push_back({i, j});

  for (auto [an, coords] : areas) {
    int sum = 0, div = coords.size();
    if (div == 0) continue;
    for (auto [x, y] : coords) sum += board[x][y];
    int normal = sum / div;
    for (auto [x, y] : coords) board[x][y] = normal;
  }
}

// 입력
void input() {
  cin >> n >> l >> r;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
}

// 초기화
void init() {
  for (int i = 0; i < n; ++i) fill(area[i], area[i] + n, 0);
}

// 디버깅
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
  int an = 1;
  while (true) {
    bool res = false;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) res |= bfs(i, j, an++);
    if (!res) break;
    move();
    init();
    day += 1;
  }
  cout << day;
  return 0;
}