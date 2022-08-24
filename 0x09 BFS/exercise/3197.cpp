#include <bits/stdc++.h>

using namespace std;

const int range = 1500;

int r, c;
string plane[range + 5];
bool ice_visited[range + 5][range + 5];
bool swan_visited[range + 5][range + 5];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

void melt(queue<pair<int, int>>& q, queue<pair<int, int>>& aq) {
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    ice_visited[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (ice_visited[nx][ny]) continue;
      if (plane[nx][ny] == 'X') aq.push({nx, ny});
      ice_visited[nx][ny] = true;
    }
  }
  while (!aq.empty()) {
    auto [x, y] = aq.front();
    aq.pop();
    q.push({x, y});
    plane[x][y] = '.';  // 위에서 방문 처리했으므로 여기는 녹은 상태여야함
  }
}

bool bfs(queue<pair<int, int>>& q, queue<pair<int, int>>& aq) {
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (swan_visited[nx][ny]) continue;
      if (plane[nx][ny] == 'L') {
        return true;
      }
      if (plane[nx][ny] == 'X') {
        // 이번 턴에는 막혀있지만 다음 턴에는 뚫을 수 있음, 왜냐하면 지금 있는
        // 곳이 물이기 때문
        aq.push({nx, ny});
        swan_visited[nx][ny] = true;
        continue;
      }
      q.push({nx, ny});
      swan_visited[nx][ny] = true;
    }
  }
  while (!aq.empty()) {
    auto [x, y] = aq.front();
    aq.pop();
    q.push({x, y});
  }
  return false;
}

void print() {
  cout << '\n';
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << plane[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // 현재 턴에 녹는 얼음
  queue<pair<int, int>> ice_q;
  // 현재 녹는 얼음의 인접 얼음들이 다음 턴의 시작점이 된다
  queue<pair<int, int>> ice_aq;
  // 현재 턴에 백조가 탐색할 포인트
  queue<pair<int, int>> swan_q;
  // 얼음에 막혀서 현재턴에는 못하지만 다음턴에 백조가 탐색할 포인트
  queue<pair<int, int>> swan_aq;
  bool is_meet = false, is_first = true;
  int cnt = 0;
  cin >> r >> c;
  for (int i = 0; i < r; ++i) cin >> plane[i];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (plane[i][j] == 'L' && is_first) {
        swan_q.push({i, j});
        plane[i][j] = '.';
        swan_visited[i][j] = true;
        is_first = false;
      }
      if (plane[i][j] != 'X') ice_q.push({i, j});
    }
  }
  while (!is_meet) {
    melt(ice_q, ice_aq);
    cnt += 1;
    is_meet = bfs(swan_q, swan_aq);
  }
  cout << cnt << '\n';
  return 0;
}