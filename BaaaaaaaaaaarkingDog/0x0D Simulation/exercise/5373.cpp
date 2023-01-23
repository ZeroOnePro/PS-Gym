#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define pqtiii priority_queue<tiii, vector<tiii>, greater<tiii>>

const int range = 25;

struct shark {
  int x, y;
  int w;
  int eat;
} shark;

int n, t;
int board[range][range];
int dist[range][range];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= n || y >= n; }

// 상어보다 작은 물고기 없을 때 false 리턴
void bfs(int x, int y, pqtiii& pq) {
  queue<pii> q;
  for (int i = 0; i < n; ++i) fill(dist[i], dist[i] + n, -1);
  q.push({x, y});
  dist[x][y] = 0;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny] >= 0 || board[nx][ny] > shark.w) continue;
      // 먹을 물고기 좌표저장
      // 거리 순으로 먹을 수 있는게 다 수개일 때 위부터, 위가 여러개면 왼쪽부터
      if (board[nx][ny] != 0 && board[nx][ny] < shark.w)
        pq.push({dist[x][y] + 1, nx, ny});
      q.push({nx, ny});
      dist[nx][ny] = dist[x][y] + 1;
    }
  }
}

// 매 턴마다 시작점 변경해주고 걸린 시간 재는 함수
bool simulation() {
  pqtiii pq;
  bfs(shark.x, shark.y, pq);
  // 먹을 물고기 없으면 멈춘다
  if (pq.size() == 0) return false;
  // 있으면 갱신 해주기
  // 1. 상어의 시작좌표
  // 2. 경과 시간
  // 3. 상어가 먹은게 자신의 크기와 같아지면 레벨 변경
  // 4. 먹은 칸 0으로 변경
  auto [d, x, y] = pq.top();
  t += d;
  shark.eat += 1;
  if (shark.eat == shark.w) {
    shark.w += 1;
    shark.eat = 0;
  }
  board[x][y] = 0;
  board[shark.x][shark.y] = 0;
  shark.x = x;
  shark.y = y;
  return true;
}

// 입력
void input() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        shark.x = i;
        shark.y = j;
      }
    }
  shark.w = 2;
  shark.eat = 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  while (simulation())
    ;
  cout << t;
  return 0;
}