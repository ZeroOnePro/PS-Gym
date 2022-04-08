#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n, m;
int iceberg[302][303];
bool visited[303][303];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int nx, int ny) { return (nx < 0 || nx >= n || ny < 0 || ny >= m); }

void melt_simulation() {
  int ocean[303][303] = {0};
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      if (iceberg[row][col] <= 0) continue;
      for (int dir = 0; dir < 4; dir++) {
        int nx = row + dx[dir];
        int ny = col + dy[dir];
        if (check(nx, ny)) continue;
        // 모든 0이 아닌 칸은 동시에 녹는다.
        // iceberg[row]][col] -= 1을 하면 각 칸이 동시에 녹는게 아닌 차례로
        // 하나하나 녹는 것이다.
        if (iceberg[nx][ny] == 0) {
          ocean[row][col] += 1;
        }
      }
    }
  }
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      iceberg[row][col] = max(0, iceberg[row][col] - ocean[row][col]);
    }
  }
}

void bfs(queue<pair<int, int>>& q) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (check(nx, ny)) continue;
      if (visited[nx][ny] || iceberg[nx][ny] <= 0) continue;
      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> iceberg[i][j];
    }
  }
  int area = 0, year = 0;
  while (true) {
    year += 1;
    area = 0;
    melt_simulation();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!visited[i][j] && iceberg[i][j] > 0) {
          area += 1;
          q.push({i, j});
          visited[i][j] = true;
          bfs(q);
        }
      }
    }
    for (int i = 0; i < n; ++i) fill(visited[i], visited[i] + m, false);
    q = queue<pair<int, int>>();

    if (area >= 2) break;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum += iceberg[i][j];
      }
    }
    if (sum == 0) {
      cout << 0;
      return 0;
    }
  }
  cout << year << '\n';
  return 0;
}