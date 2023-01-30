#include <bits/stdc++.h>

using namespace std;

#define pi2 pair<int, int>

const int range = 25;

int w, h, cnt = 1;

pi2 st;
pi2 dirty[15];
string board[range];
int dist[15][range][range];  // i번 좌표에서 다른 모든 점까지의 최단 거리, 중간
                             // 정점을 통해 업데이트 되는게 아니므로 플로이드
                             // 워셜이나 다익스트라를 사용하는 경우와는 다르다
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= h || y >= w; }

int bfs(int x, int y, int num) {
  queue<pi2> q;
  for (int j = 0; j < h; ++j) fill(dist[num][j], dist[num][j] + w, -1);
  q.push({x, y});
  dist[num][x][y] = 0;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] == 'x' || dist[num][nx][ny] >= 0)
        continue;
      dist[num][nx][ny] = dist[num][x][y] + 1;
      q.push({nx, ny});
    }
  }
  // 모두 탐색했음에도 불구하고 못 닿는다면 불가능 케이스
  return -1;
}

void input() {
  for (int i = 0; i < h; ++i) {
    cin >> board[i];
    for (int j = 0; j < w; ++j)
      if (board[i][j] == '*')
        dirty[cnt++] = {i, j};
      else if (board[i][j] == 'o')
        st = {i, j};
  }
  cnt -= 1;
}

void init() {
  for (int i = 0; i < 15; ++i) dirty[i] = {};
  fill(board, board + h, "");
  cnt = 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    input();
    int mn = INT_MAX;
    vector<int> order(cnt);
    for (int i = 0; i < cnt; ++i) order[i] = i + 1;
    bfs(st.first, st.second, 0);
    for (int i = 0; i < cnt; ++i)
      bfs(dirty[i + 1].first, dirty[i + 1].second, i + 1);
    bool is_possible = true;
    do {
      int sum = dist[0][dirty[order[0]].first][dirty[order[0]].second];
      if (sum == -1) break;
      for (int i = 1; i < cnt; ++i) {
        // 순서대로 거리 계산해서 갱신
        int d =
            dist[order[i - 1]][dirty[order[i]].first][dirty[order[i]].second];
        if (d == -1) {
          is_possible = false;
          break;
        }
        sum += d;
      }
      if (is_possible) mn = min(mn, sum);
    } while (next_permutation(order.begin(), order.end()));
    if (mn == INT_MAX)
      cout << -1 << '\n';
    else
      cout << mn << '\n';
    init();
  }
  return 0;
}

/**
 * 놓쳤던 점
 * 한 쓰레기에서 다른 쓰레기까지의 거리는 변하지 않는데 매번 구해주고 있는
 * 반복작업이 일어났다, 그 점을 놓쳐서 다이나믹 프로그래밍의 Memoization
 * 기법을 적용할 생각을 못했다
 *
 */