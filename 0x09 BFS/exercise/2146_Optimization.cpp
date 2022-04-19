// 여러 시작점이 있는 경우의 bfs풀이를 응용한 다리 찾기 문제
// 참고링크:
// http://www.secmem.org/blog/2019/03/07/%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%EB%8C%80%EB%B9%84-%ED%8A%B9%EA%B0%95/
// 59 슬라이드

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

int construct_bridge(queue<pair<int, int>>& q, int* min_len) {
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
      // 같은 구역이면, 더 볼 필요없다.
      if (country[nx][ny] == country[cur.x][cur.y]) continue;
      // 다른 구역을 만났을 때
      if (country[nx][ny] != 0) {
        *min_len = min(*min_len, dist[cur.x][cur.y] + dist[nx][ny]);
      } else {
        q.push({nx, ny});
        country[nx][ny] =
            country[cur.x][cur.y];  // 바다를 섬으로 채운다, dist배열을 초기화할
                                    // 필요가 없어진다.
        dist[nx][ny] = dist[cur.x][cur.y] + 1;
      }
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

  // 모든 점 하나하나 할 필요없이 섬을 단위(시작점)로 동시에 bfs를 수행한다.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (country[i][j] >= 1) {
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }
  int min_bridge_len = INT_MAX;
  construct_bridge(q, &min_bridge_len);
  cout << min_bridge_len << '\n';
  return 0;
}