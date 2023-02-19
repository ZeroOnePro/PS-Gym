#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 55;

int r, c;
string plane[range];

pi2 hedgehog, cave;
vector<pi2> water;

int dist[2][range][range];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

// type 0은 시작점이 물, 1은 고슴도치
void bfs(int type) {
  queue<pi2> q;
  if (type == 0) {
    for (auto [x, y] : water) {
      q.push({x, y});
      dist[type][x][y] = 0;
    }
  } else {
    auto [x, y] = hedgehog;
    q.push({x, y});
    dist[type][x][y] = 0;
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || plane[nx][ny] == 'X' || dist[type][nx][ny] >= 0)
        continue;
      if (type == 0 && plane[nx][ny] == 'D') continue;
      if (type == 1 && dist[1 - type][nx][ny] >= 0 &&
          dist[1 - type][nx][ny] <= dist[type][x][y] + 1)
        continue;
      q.push({nx, ny});
      dist[type][nx][ny] = dist[type][x][y] + 1;
    }
  }
}

void print(int type) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) cout << dist[type][i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    cin >> plane[i];
    for (int j = 0; j < c; ++j) {
      if (plane[i][j] == 'S')
        hedgehog = {i, j};
      else if (plane[i][j] == '*')
        water.push_back({i, j});
      else if (plane[i][j] == 'D')
        cave = {i, j};
    }
  }
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < r; ++j) fill(dist[i][j], dist[i][j] + c, -1);
  bfs(0);
  bfs(1);
  auto [x, y] = cave;
  if (dist[1][x][y] == -1) {
    cout << "KAKTUS";
    return 0;
  } else
    cout << dist[1][x][y];
  return 0;
}