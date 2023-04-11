#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 105;

int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

map<pi2, vector<pi2>> light;
int plane[range][range];
bool vis[range][range];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int bfs() {
  queue<pi2> q;
  int room = 1;
  plane[0][0] = 1;
  q.push({0, 0});
  vis[0][0] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto point : light[{x, y}]) {
      auto [nx, ny] = point;
      plane[nx][ny] = 1;
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || plane[nx][ny] == 0) continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
      room += 1;
    }
  }
  return room;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int room = 0;
  cin >> n >> m;
  while (m--) {
    int cx, cy, a, b;
    cin >> cx >> cy >> a >> b;
    --cx;
    --cy;
    --a;
    --b;
    light[{cx, cy}].push_back({a, b});
  }
  while (true) {
    for (int i = 0; i < n; ++i) fill(vis[i], vis[i] + n, false);
    int width = bfs();
    if (room < width)
      room = width;
    else
      break;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cnt += plane[i][j];
    }
  }
  cout << cnt << '\n';
  return 0;
}