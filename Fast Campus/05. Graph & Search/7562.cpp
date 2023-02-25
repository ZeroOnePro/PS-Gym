#include <bits/stdc++.h>

using namespace std;

// bfs
// 최단 경로
// 특이점: 상하좌우 이동 + 대각선 이동

#define x first
#define y second

int tc, l;

int board[302][302];
int dist[302][302];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void bfs(queue<pair<int, int>>& q, int end_x, int end_y) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 8; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx == end_x && ny == end_y) {
        cout << dist[cur.x][cur.y] + 1 << '\n';
        return;
      }
      if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
      if (dist[nx][ny] >= 0) continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[cur.x][cur.y] + 1;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> tc;
  while (tc--) {
    int start_x, start_y, end_x, end_y;
    cin >> l >> start_x >> start_y >> end_x >> end_y;
    if (start_x == end_x && start_y == end_y) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = 0; i < l; ++i) fill(dist[i], dist[i] + l, -1);
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;
    bfs(q, end_x, end_y);
    q = queue<pair<int, int>>();
  }
  return 0;
}