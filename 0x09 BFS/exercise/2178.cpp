#include <bits/stdc++.h>

using namespace std;

// 입력이 붙어서 들어오는 특이점이 있다. => string을 활용하자

#define x first
#define y second

string board[102];
int dist[102][102];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(queue<pair<int, int>> &q) {
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
      dist[nx][ny] = dist[cur.x][cur.y] + 1;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> board[i];

  // fill함수가 배열채우는 용도인 것 같은데 확인해보기
  for (int i = 0; i < n; ++i) fill(dist[i], dist[i] + m, -1);

  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 0;

  bfs(q);

  cout << dist[n - 1][m - 1] + 1 << '\n';

  return 0;
}