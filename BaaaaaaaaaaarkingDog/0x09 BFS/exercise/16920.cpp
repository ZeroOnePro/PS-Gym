#include <bits/stdc++.h>

using namespace std;

int n, m, p;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[1005];
int s[11];
int freq[11];
set<tuple<int, int, int>> start[11];

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

void bfs(queue<tuple<int, int, int>>& q, bool* pc) {
  while (!q.empty()) {
    auto [age, x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (board[nx][ny] != '.') continue;
      if (age == 0) continue;
      if (age == 1) {
        int idx = board[x][y] - '0';
        start[idx].insert({s[idx], nx, ny});
      }
      q.push({age - 1, nx, ny});
      board[nx][ny] = board[x][y];
      *pc = true;
    }
  }
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> p;
  queue<tuple<int, int, int>> q;
  for (int i = 1; i <= p; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
    for (int j = 0; j < m; ++j)
      if (isdigit(board[i][j])) {
        int idx = board[i][j] - '0';
        start[idx].insert({s[idx], i, j});
      }
  }
  // 각 턴마다 age가 0인 것들이 다음 턴 시작점
  while (true) {
    bool possible_case = false;
    for (int i = 1; i <= p; ++i) {
      if (start[i].size()) {
        for (auto point : start[i]) {
          q.push(point);
        }
      }
      start[i].clear();
      bfs(q, &possible_case);
    }
    if (!possible_case) break;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      freq[board[i][j] - '0'] += 1;
    }
  }
  for (int i = 1; i <= p; ++i) cout << freq[i] << ' ';
  return 0;
}