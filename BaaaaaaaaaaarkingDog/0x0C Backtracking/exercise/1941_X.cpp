#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool mask[25];
bool visited[5][5];
string plane[5];
bool able[5][5];

bool OOB(int x, int y) { return x < 0 || x >= 5 || y < 0 || y >= 5; }

bool bfs(queue<pair<int, int>>& q) {
  int dasom = 0;
  int area = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    dasom += (plane[x][y] == 'S');
    area += 1;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || visited[nx][ny] || !able[nx][ny]) continue;
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  return dasom >= 4 && area == 7;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cnt = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < 5; ++i) cin >> plane[i];
  fill(mask + 7, mask + 25, true);
  do {
    for (int i = 0; i < 25; ++i) {
      if (!mask[i]) {
        int x = i / 5;
        int y = i % 5;
        able[x][y] = true;
        if (q.empty()) {
          q.push({x, y});
          visited[x][y] = true;
        }
      }
    }
    // 조합을 뽑는데 한 칸 씩 늘려나가면서 S의 포함 수를 고려하면서
    // pruning시켜주면 백트래킹 문제로 환원되니?
    // 완전탐색에서 프루닝만 시켜주면 백트래킹, 근데 지금 푼 방식은 완전탐색임
    // 정답이 안 될거같으면 미리 잘라낸다
    // bfs & check
    cnt += bfs(q);
    // init
    q = queue<pair<int, int>>();
    for (int i = 0; i < 5; ++i) {
      fill(able[i], able[i] + 5, false);
      fill(visited[i], visited[i] + 5, false);
    }
  } while (next_permutation(mask, mask + 25));
  cout << cnt;
  return 0;
}