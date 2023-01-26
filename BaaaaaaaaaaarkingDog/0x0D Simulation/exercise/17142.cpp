#include <bits/stdc++.h>

using namespace std;

#define pi2 pair<int, int>

const int range = 55;

int n, m, st_num, mn_dist = INT_MAX;
int board[range][range];
int dist[range][range];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

vector<pi2> st, emp;

void print() {
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << dist[i][j] << ' ';
    cout << '\n';
  }
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 2)
        st.push_back({i, j});
      else if (board[i][j] == 0)
        emp.push_back({i, j});
    }
  st_num = st.size();
}

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

void bfs(vector<pi2>& v) {
  int local_mx = -1;
  queue<pi2> q;
  for (int i = 0; i < n; ++i) fill(dist[i], dist[i] + n, -1);
  for (auto [x, y] : v) {
    q.push({x, y});
    dist[x][y] = 0;
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
      if (board[nx][ny] != 2) local_mx = max(local_mx, dist[nx][ny]);
    }
  }
  bool is_possible = true;
  for (auto [x, y] : emp)
    if (dist[x][y] == -1) is_possible = false;
  if (is_possible) mn_dist = min(mn_dist, local_mx);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  vector<int> cur_st(st_num);
  fill(cur_st.begin() + (st_num - m), cur_st.end(), 1);
  do {
    vector<pi2> sts;
    // 시작점으로 선택된 것
    // 선택되지 못한 것은 비활성 바이러스 된다 => 2를 지나갈 수 있는 칸으로
    // 만들어주면 된다
    for (int i = 0; i < st_num; ++i)
      if (cur_st[i] == 1) sts.push_back(st[i]);
    // bfs 돌려서 최단 거리 중 제일 큰 값 나오게 만들기
    bfs(sts);
  } while (next_permutation(cur_st.begin(), cur_st.end()));
  if (emp.size() > 0)
    if (mn_dist == INT_MAX)
      cout << -1;
    else
      cout << mn_dist;
  else
    cout << 0;
  return 0;
}