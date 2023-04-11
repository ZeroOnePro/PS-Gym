#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 1505;

int r, c;

string lake[range];
bool vis[2][range][range];

void print() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) cout << lake[i][j] << ' ';
    cout << '\n';
  }
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

void melt(queue<pi2>& q, queue<pi2>& nq) {
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[1][nx][ny]) continue;
      if (lake[nx][ny] == 'X') {
        nq.push({nx, ny});
        vis[1][nx][ny] = true;
        continue;
      }
      q.push({nx, ny});
      vis[1][nx][ny] = true;
    }
  }
  while (!nq.empty()) {
    auto [x, y] = nq.front();
    q.push({x, y});
    lake[x][y] = '.';
    nq.pop();
  }
}

bool bfs(queue<pi2>& q, queue<pi2>& nq) {
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[0][nx][ny]) continue;
      if (lake[nx][ny] == 'L') return true;
      if (lake[nx][ny] == 'X') {
        nq.push({nx, ny});
        vis[0][nx][ny] = true;
        continue;
      }
      q.push({nx, ny});
      vis[0][nx][ny] = true;
    }
  }
  while (!nq.empty()) {
    q.push(nq.front());
    nq.pop();
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  bool is_first = true;
  queue<pi2> swan, nxt_swan, water, nxt_water;
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    cin >> lake[i];
    for (int j = 0; j < c; ++j) {
      if (lake[i][j] == 'L' && is_first) {
        is_first = false;
        swan.push({i, j});
        vis[0][i][j] = true;
        lake[i][j] = '.';
      }
      if (lake[i][j] != 'X') {
        water.push({i, j});
        vis[1][i][j] = true;
      }
    }
  }
  int day = 0;
  bool is_meet = false;
  while (!is_meet) {
    melt(water, nxt_water);
    day += 1;
    is_meet = bfs(swan, nxt_swan);
  }
  cout << day;
  return 0;
}