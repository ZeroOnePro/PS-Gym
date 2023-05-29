#include <bits/stdc++.h>

using namespace std;

const int range = 20;

typedef pair<int, int> pi2;

#define EMPTY make_pair(-1, -1)

int curr_t;
int n, m;
bool vis[range][range];
int dist[range][range];
int board[range][range];
pi2 store[35];
pi2 people[35];

// 입력
void input() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    store[i] = make_pair(x - 1, y - 1);
  }
}

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void init() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      vis[i][j] = false;
      dist[i][j] = 0;
    }
}

// 사람을 1초에 한 번만 이동시켜야함
// 사람이 이동할 다음 칸을 정하기 위해 각 편의점을 시작점으로 bfs 돌린다
// 맵에서 2번은 블럭된 칸(점유된 베이스캠프, 편의점)을 의미
// bfs
void bfs(pi2 st) {
  init();
  queue<pi2> q;
  int x = st.first, y = st.second;
  q.push({x, y});
  vis[x][y] = true;
  dist[x][y] = 0;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 2) continue;
      dist[nx][ny] = dist[x][y] + 1;
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

void simulation() {
  // step 1. 격자 내의 사람 편의점으로 이동시키기
  for (int i = 0; i < m; ++i) {
    // 사람이 격자 밖에 있거나 모두 편의점 도착하면 pass
    if (people[i] == EMPTY || people[i] == store[i]) continue;

    bfs(store[i]);

    int px = people[i].first, py = people[i].second;
    int min_dist = INT_MAX;
    int min_x = -1, min_y = -1;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = px + dx[dir], ny = py + dy[dir];
      if (!OOB(nx, ny) && vis[nx][ny] && min_dist > dist[nx][ny]) {
        min_dist = dist[nx][ny];
        min_x = nx;
        min_y = ny;
      }
    }
    // 우선순위가 가장 높은 위치로 한 칸 이동
    people[i] = make_pair(min_x, min_y);
  }

  // step 2. 편의점 도착한 사람 체크
  for (int i = 0; i < m; i++) {
    if (people[i] == store[i]) {
      int px, py;
      tie(px, py) = people[i];
      board[px][py] = 2;
    }
  }

  // Step 3. 현재 시간 curr_t에 대해 curr_t ≤ m를 만족한다면 t번 사람이 베이스
  // 캠프로 이동

  // curr_t가 m보다 크다면 패스합니다.
  if (curr_t > m) return;

  // Step 3-1. 편의점으로부터 가장 가까운 베이스 캠프를 고르기
  bfs(store[curr_t - 1]);

  // Step 3-2. 편의점에서 가장 가까운 베이스 캠프를 선택합니다.
  int min_dist = INT_MAX;
  int min_x = -1, min_y = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 방문 가능한 베이스 캠프 중
      // 거리가 가장 가까운 위치를 찾아줍니다.
      if (vis[i][j] && board[i][j] == 1 && min_dist > dist[i][j]) {
        min_dist = dist[i][j];
        min_x = i;
        min_y = j;
      }
    }
  }

  // 우선순위가 가장 높은 베이스 캠프로 이동
  people[curr_t - 1] = make_pair(min_x, min_y);
  // 해당 베이스 캠프는 앞으로 이동이 불가능한 칸임을 표시
  board[min_x][min_y] = 2;
}

// 모든 사람이 편의점에 도착했는지 체크
bool check() {
  for (int i = 0; i < m; ++i)
    if (people[i] != store[i]) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  for (int i = 0; i < m; ++i) people[i] = EMPTY;
  while (true) {
    curr_t++;
    simulation();
    if (check()) break;
  }
  cout << curr_t;
  return 0;
}