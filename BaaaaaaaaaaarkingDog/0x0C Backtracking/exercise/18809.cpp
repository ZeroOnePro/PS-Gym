#include <bits/stdc++.h>

using namespace std;

int n, m;

int plane[55][55];
int copied[55][55];
int dist[2][55][55];  // 1차원은 초록 배양액, 2차원은 빨강 배양액

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 맵의 탐색 영역의 각 포인트는 다음 네가지 상태 중 하나임
enum Name { GREEN, RED, EMPTY, FLOWER };

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(queue<tuple<int, int, int>>& q) {
  int cnt = 0;
  for (int i = 0; i < 55; ++i) copy(plane[i], plane[i] + 55, copied[i]);
  while (!q.empty()) {
    auto [color, x, y] = q.front();
    q.pop();
    // 서로 만나서 꽃 피우면 그 이후로는 진행 못함
    if (copied[x][y] == FLOWER) continue;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (copied[nx][ny] == 0 || dist[color][nx][ny] >= 0) continue;
      if (dist[1 - color][nx][ny] >= 0) {
        // 꽃 피울 수 있는 조건
        if (dist[1 - color][nx][ny] == dist[color][x][y] + 1) {
          cnt += 1;
          dist[color][nx][ny] = dist[color][x][y] + 1;
          copied[nx][ny] = FLOWER;
        }
        continue;
      }
      q.push({color, nx, ny});
      dist[color][nx][ny] = dist[color][x][y] + 1;
    }
  }
  return cnt;
}

void init() {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      fill(dist[i][j], dist[i][j] + m, -1);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<tuple<int, int, int>> q;
  pair<int, int> st[10];
  int r, g, ocher = 0, ans = 0;
  cin >> n >> m >> g >> r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> plane[i][j];
      if (plane[i][j] == 2) st[ocher++] = {i, j};
    }
  }
  // st 수열은 원소가 0, 1, 2로 구성되있고, 총 ocher개 있음
  // 0은 초록 배양액, 1은 빨강 배양액, 2는 빈 황토를 의미
  vector<int> seq(ocher);
  fill(seq.begin() + g, seq.begin() + g + r, RED);
  fill(seq.begin() + g + r, seq.end(), EMPTY);

  // 선택된 황토에 배양액 뿌려보고 최대값 찾기
  init();
  do {
    for (int i = 0; i < ocher; ++i) {
      if (seq[i] != EMPTY) {
        auto [x, y] = st[i];
        q.push({seq[i], x, y});
        dist[seq[i]][x][y] = 0;
      }
    }
    // 갱신
    ans = max(ans, bfs(q));
    // 초기화
    q = queue<tuple<int, int, int>>();
    init();
  } while (next_permutation(seq.begin(), seq.end()));
  cout << ans;
  return 0;
}