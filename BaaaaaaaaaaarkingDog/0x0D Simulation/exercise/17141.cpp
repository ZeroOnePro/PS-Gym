#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 55;

int n, m, len, mn = INT_MAX;
int board[range][range];
vector<pi2> st, et;

enum { EMPTY, WALL, VIRUS };

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
      if (board[i][j] == VIRUS) {
        st.push_back({i, j});
        et.push_back({i, j});
      } else if (board[i][j] == EMPTY)
        et.push_back({i, j});
    }
  len = st.size();
}

int dist[range][range];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

void bfs(vector<int>& v) {
  queue<pi2> q;
  for (int i = 0; i < n; ++i) fill(dist[i], dist[i] + n, -1);
  for (int i = 0; i < m; ++i) {
    auto [x, y] = st[v[i]];
    q.push({x, y});
    dist[x][y] = 0;
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] == WALL || dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }
  int local_mx = 0;
  for (auto [x, y] : et) {
    if (dist[x][y] == -1) return;
    local_mx = max(dist[x][y], local_mx);
  }
  mn = min(local_mx, mn);
}

// 바이러스 위치 조합 생성
vector<int> seq(15);
void all_case(int cur, int prev) {
  if (cur == m) {
    bfs(seq);
    return;
  }
  for (int i = 0; i < len; ++i) {
    if (i <= prev) continue;
    seq[cur] = i;
    all_case(cur + 1, seq[cur]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  all_case(0, -1);
  if (mn == INT_MAX) mn = -1;
  cout << mn;
  return 0;
}