#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n, m, k, c;
int board[range][range];  // 맵
int adj[range][range];    // 인접(성장에 필요)
int b[range][range];      // 새로 번식될 공간
int vis[range][range];    // 제초제 뿌려진 칸

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void input() {
  cin >> n >> m >> k >> c;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
}

// 1년이 지날 때마다 제초제 양 1씩 감소
void remove_vis() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (vis[i][j] > 0) vis[i][j] -= 1;
    }
}

void grow() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (board[i][j] > 0)
        for (int dir = 0; dir < 4; ++dir) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if (OOB(nx, ny)) continue;
          if (board[nx][ny] > 0) adj[i][j] += 1;
        }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (adj[i][j] > 0) {
        board[i][j] += adj[i][j];
      }
  for (int i = 0; i < n; ++i) {
    fill(adj[i], adj[i] + n, 0);
  }
}

void breed() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (board[i][j] > 0)
        for (int dir = 0; dir < 4; ++dir) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if (OOB(nx, ny)) continue;
          if (board[nx][ny] == 0 && vis[nx][ny] == 0) {
            adj[i][j] += 1;
            b[nx][ny] = true;
          }
        }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (adj[i][j] > 0)
        for (int dir = 0; dir < 4; ++dir) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if (OOB(nx, ny)) continue;
          if (b[nx][ny]) board[nx][ny] += board[i][j] / adj[i][j];
        }
  for (int i = 0; i < n; ++i) {
    fill(adj[i], adj[i] + n, 0);
    fill(b[i], b[i] + n, false);
  }
}

// (x, y)에서 제초제를 뿌렸을 때 제거되는 나무 개수 리턴
// 벽에 뿌리는 경우에 유의해라(-1이다, 없어지는 나무의 개수에 누적되지 않게
// 조심)
long long find_point(int x, int y) {
  long long sum = (long long)board[x][y];
  int diax[] = {-1, -1, 1, 1};
  int diay[] = {-1, 1, 1, -1};
  for (int dir = 0; dir < 4; ++dir) {
    for (int i = 1; i <= k; ++i) {
      int nx = x + i * diax[dir];
      int ny = y + i * diay[dir];
      if (OOB(nx, ny)) continue;
      if (board[nx][ny] == -1 || board[nx][ny] == 0) break;
      if (board[nx][ny] != -1) sum += (long long)board[nx][ny];
    }
  }
  return sum;
}

void spread(int x, int y) {
  board[x][y] = 0;
  vis[x][y] = c + 1;
  int diax[] = {-1, -1, 1, 1};
  int diay[] = {-1, 1, 1, -1};
  for (int dir = 0; dir < 4; ++dir) {
    for (int i = 1; i <= k; ++i) {
      int nx = x + i * diax[dir];
      int ny = y + i * diay[dir];
      if (OOB(nx, ny)) continue;
      vis[nx][ny] = c + 1;
      if (board[nx][ny] == -1 || board[nx][ny] == 0) break;
      if (board[nx][ny] != -1) board[nx][ny] = 0;
    }
  }
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%2d ", board[i][j]);
    cout << '\n';
  }
  cout << '\n';
}

int simulation() {
  int x = -1, y = -1, sum = 0;
  remove_vis();
  grow();
  breed();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (board[i][j] <= 0) continue;
      int rm = find_point(i, j);
      if (sum < rm) {
        sum = rm;
        x = i;
        y = j;
      }
    }
  spread(x, y);
  return sum;
}

int main() {
  long long ans = 0;
  input();
  while (m--) {
    ans += simulation();
    print();
  }
  cout << ans;
  return 0;
}