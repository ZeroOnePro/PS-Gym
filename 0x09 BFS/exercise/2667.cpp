#include <bits/stdc++.h>

using namespace std;

// 2차원 bfs
// flood fill
// 영역의 개수, 너비 구하기

#define x first
#define y second

int n;

string apartment_map[25];
bool visited[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(queue<pair<int, int>>& q) {
  int width = 0;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (visited[nx][ny] || apartment_map[nx][ny] != '1') continue;
      q.push({nx, ny});
      visited[nx][ny] = true;
      width += 1;
    }
  }
  return width;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<pair<int, int>> q;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> apartment_map[i];
  }
  int area = 0;
  priority_queue<int, vector<int>, greater<int>> widths;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[i][j] && apartment_map[i][j] == '1') {
        q.push({i, j});
        visited[i][j] = true;
        widths.push(bfs(q) + 1);
        area += 1;
      }
    }
  }
  cout << area << '\n';
  while (!widths.empty()) {
    cout << widths.top() << ' ';
    widths.pop();
  }
  return 0;
}