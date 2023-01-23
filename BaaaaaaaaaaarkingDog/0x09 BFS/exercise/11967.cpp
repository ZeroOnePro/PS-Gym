#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

map<pair<int, int>, vector<pair<int, int>>> light;
int plane[105][105];
bool vis[105][105];

void print() {
  cout << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << plane[i][j] << ' ';
    }
    cout << '\n';
  }
}

void print_point(int x, int y) { cout << "(" << x << ", " << y << ")\n"; }

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > n; }

int bfs(queue<pair<int, int>>& q, int area) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    auto [x, y] = cur;
    for (auto point : light[{x, y}]) {
      auto [nx, ny] = point;
      plane[nx][ny] = 1;
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (plane[nx][ny] == 0 || vis[nx][ny]) continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
      area += 1;
    }
  }
  return area;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int cx, cy, a, b;
    cin >> cx >> cy >> a >> b;
    light[{cx, cy}].push_back({a, b});
  }
  plane[1][1] = 1;
  int area = 0;
  while (true) {
    q.push({1, 1});
    vis[1][1] = true;
    int tmp = 1;
    tmp = bfs(q, tmp);
    for (int i = 1; i <= n; ++i) fill(vis[i], vis[i] + n + 1, false);
    // (1,1)을 시작점으로 하는 영역의 최대 크기에 도달했을 때 종료
    if (area < tmp)
      area = tmp;
    else
      break;
  }
  int cnt = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cnt += plane[i][j];
    }
  }
  cout << cnt << '\n';
  return 0;
}