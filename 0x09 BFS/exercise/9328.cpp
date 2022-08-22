#include <bits/stdc++.h>

using namespace std;

const int range = 100;

int w, h, cnt;
char plane[range + 5][range + 5];
bool visited[range + 5][range + 5];
int key[26];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 외곽의 어느 포인트에서던지 들어갈 수 있다
// 맵을 감싸고 있는 테두리를 이용할 것이다
bool OOB(int x, int y) { return x < 0 || x > h + 1 || y < 0 || y > w + 1; }

void bfs(void) {
  queue<pair<int, int>> q;
  queue<pair<int, int>> door[26];
  // 테두리의 시작점에서 시작해서 맵으로 진입
  q.push({0, 0});
  visited[0][0] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (visited[nx][ny] || plane[nx][ny] == '*') continue;
      // 열쇠
      // 이전에 만났던 문이 있었다면 이제는 열 수 있다!
      if (plane[nx][ny] >= 'a' && plane[nx][ny] <= 'z') {
        int key_index = plane[nx][ny] - 'a';
        key[key_index] = 1;
        while (!door[key_index].empty()) {
          auto [sx, sy] = door[key_index].front();
          door[key_index].pop();
          q.push({sx, sy});
        }
      }
      // 문
      // 1. 열 수 있으나 키가 아직 미발견됬을 경우
      // 2. 열 수 없는 경우
      // 3. 이미 키가 있어서 열 수 있는 경우
      else if (plane[nx][ny] >= 'A' && plane[nx][ny] <= 'Z') {
        int key_index = tolower(plane[nx][ny]) - 'a';
        if (!key[key_index]) {
          door[key_index].push({nx, ny});
          continue;
        }
      }
      // 문서
      else if (plane[nx][ny] == '$')
        cnt += 1;
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

void init(void) {
  for (int i = 0; i <= h + 1; ++i) {
    fill(plane[i], plane[i] + w + 2, 0);
    fill(visited[i], visited[i] + w + 2, false);
  }
  fill(key, key + 26, 0);
  cnt = 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string keys;
    cin >> h >> w;
    for (int i = 1; i <= h; ++i)
      for (int j = 1; j <= w; ++j) cin >> plane[i][j];
    cin >> keys;
    if (keys != "0")
      for (char c : keys) key[c - 'a'] = 1;
    bfs();
    cout << cnt << '\n';
    init();
  }
  return 0;
}