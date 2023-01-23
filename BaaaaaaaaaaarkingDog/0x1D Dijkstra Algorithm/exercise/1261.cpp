#include <bits/stdc++.h>

using namespace std;

#define tiii tuple<int, int, int>

const int range = 105;
const int INF = 0x3f3f3f3f;

int n, m;

int plane[range][range];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int dist[range][range];

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > m; }

void dijkstra() {
  priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
  for (int i = 1; i <= n; ++i) fill(dist[i], dist[i] + m + 1, INF);
  dist[1][1] = 0;
  pq.push({0, 1, 1});
  while (!pq.empty()) {
    auto [d, x, y] = pq.top();
    pq.pop();
    if (dist[x][y] != d) continue;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      int new_dist = plane[nx][ny] + dist[x][y];
      if (dist[nx][ny] > new_dist) {
        dist[nx][ny] = new_dist;
        pq.push({new_dist, nx, ny});
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) plane[i][j + 1] = s[j] - '0';
  }
  dijkstra();
  cout << dist[n][m] << '\n';
  return 0;
}