#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int range = 10;

enum { EMPTY = 0, WALL = 1, VIRUS = 2 };

int n, m, mx = -1;

int board[range][range];
int copied[range][range];
bool vis[range][range];
int seq[5];
vector<pii> st;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= m; }

// 시작점이 2인 것들을 모두 큐에넣고 bfs 돌리기
void bfs() {
  queue<pii> q;
  for (int i = 0; i < n; ++i) fill(vis[i], vis[i] + m, false);
  for (pii p : st) {
    auto [x, y] = p;
    vis[x][y] = true;
    q.push({x, y});
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || copied[nx][ny] != EMPTY) continue;
      if (vis[nx][ny]) continue;
      copied[nx][ny] = VIRUS;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
}

// 안전 영역의 개수 세기
int count_safe_area() {
  int sum = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) sum += (copied[i][j] == EMPTY);
  return sum;
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << copied[i][j] << ' ';
    cout << '\n';
  }
}

// 벽을 어디세울지 뽑기
// 100C3
void all_case(int cur, int prev) {
  if (cur == 3) {
    // 맵 복사하고 벽 세우고 바이러스 다 큐에 넣어서 bfs돌리고 0의 개수 세기
    copy(*board, *board + range * range, *copied);
    for (int i = 0; i < 3; ++i) copied[seq[i] / m][seq[i] % m] = WALL;
    bfs();
    mx = max(mx, count_safe_area());
    return;
  }
  for (int i = 0; i < n * m; ++i) {
    seq[cur] = i;
    if (prev >= seq[cur]) continue;  // 증가하는 순만 뽑아주기
    if (board[i / m][i % m] != EMPTY) continue;
    all_case(cur + 1, seq[cur]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      if (board[i][j] == VIRUS) st.push_back({i, j});
    }
  all_case(0, -1);
  cout << mx;
  return 0;
}