#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n;

int country[102][102];
int dist[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void count_area(queue<pair<int, int>>& q, int area_num) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (dist[nx][ny] >= 0) continue;
      q.push({nx, ny});
      dist[nx][ny] = dist[cur.x][cur.y] + 1;
      country[nx][ny] = area_num;
    }
  }
}

int construct_bridge(queue<pair<int, int>>& q, int area_num) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      // 같은 구역이면, 더 볼 필요없다.
      if (dist[nx][ny] >= 0 || country[nx][ny] == area_num) continue;
      // 다른 구역을 만났을 때
      if (country[nx][ny] != 0 && country[nx][ny] != area_num) {
        return dist[cur.x][cur.y];
      }
      q.push({nx, ny});
      dist[nx][ny] = dist[cur.x][cur.y] + 1;
    }
  }
  return INT_MAX;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> country[i][j];
      if (country[i][j] == 1) {
        dist[i][j] = -1;
      }
    }
  }
  int country_num = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (country[i][j] >= 1 && dist[i][j] == -1) {
        q.push({i, j});
        dist[i][j] = 0;
        country[i][j] = country_num;
        count_area(q, country_num++);
      }
    }
  }
  while (!q.empty()) q.pop();
  for (int i = 0; i < n; ++i) fill(dist[i], dist[i] + n, -1);
  int min_bridge_len = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (country[i][j] >= 1) {
        q.push({i, j});
        dist[i][j] = 0;
        min_bridge_len =
            min(min_bridge_len, construct_bridge(q, country[i][j]));
      }
      while (!q.empty()) q.pop();
      for (int k = 0; k < n; ++k) fill(dist[k], dist[k] + n, -1);
    }
  }
  cout << min_bridge_len << '\n';
  return 0;
}