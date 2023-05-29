#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi2;

const int range = 30;

int n, h;
int board[range][range];   // 맵
int area[range][range];    // 영역 번호 표시
int tmp[range][range];     // 회전할 때 임시
int copied[range][range];  // 회전할 때 임시
bool vis[range][range];    // 영역 개수 파악할 때 필요
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
map<pi2, int> score;           // 영역의 쌍과 맞닿은 변의 개수
map<int, vector<pi2> > group;  // 영역에 속한 칸의 개수

// 인풋
void input() {
  cin >> n;
  h = n / 2;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> board[i][j];
}

void print(int a[][range]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << a[i][j] << ' ';
    cout << '\n';
  }
}

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

// 영역의 개수 구하기 및 다른 영역과 맞닿아 있는 변의 개수 구하는 용도
void bfs(int x, int y, int an) {
  int a = board[x][y];
  area[x][y] = an;
  queue<pi2> q;
  q.push({x, y});
  group[an].push_back({x, y});
  vis[x][y] = true;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] != a) continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
      area[nx][ny] = an;
      group[an].push_back({nx, ny});
    }
  }
}

// 맞닿아 있는 변의 개수 검사
// 인접 살펴서 다른 영역의 번호 써있으면 그게 맞닿아 있는 변의 개수
void check_another_area(int an, int x, int y) {
  queue<pi2> q;
  q.push({x, y});
  vis[x][y] = true;
  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny]) continue;
      if (area[nx][ny] != an) {
        score[{an, area[nx][ny]}] += 1;
        continue;
      }
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
}

// 맞닿아 있는 변의 수
// 그룹 a와 그룹 b의 조화로움은 (그룹 a에 속한 칸의 수 + 그룹 b에 속한 칸의 수 )
// x 그룹 a를 이루고 있는 숫자 값 x 그룹 b를 이루고 있는 숫자 값 x 그룹 a와 그룹
// b가 서로 맞닿아 있는 변의 수
int clac_score() {
  int s = 0;
  for (map<pi2, int>::iterator it = score.begin(); it != score.end(); ++it) {
    pair<int, int> p = it->first;
    int overlay = it->second;
    int g1 = p.first, g2 = p.second;
    // cout << g1 << ' ' << g2 << ' ' << overlay << '\n';
    // cout << board[group[g1].front().first][group[g1].front().second] << '\n';
    s += (group[g1].size() + group[g2].size()) * overlay *
         board[group[g1].front().first][group[g1].front().second] *
         board[group[g2].front().first][group[g2].front().second];
  }
  return s;
}

// 영역 검사
void find_area() {
  int an = 1;
  for (int i = 0; i < n; ++i) fill(vis[i], vis[i] + n, false);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (!vis[i][j]) bfs(i, j, an++);
  for (int i = 0; i < n; ++i) fill(vis[i], vis[i] + n, false);
  for (int g = 1; g < an; ++g)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (area[i][j] == g && !vis[i][j]) check_another_area(g, i, j);
}

// a를 b로 복사
void copy(int a[][range], int b[][range]) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) b[i][j] = a[i][j];
}

// 시계 90도 회전
void part_rotate(int sx, int sy, int ex, int ey) {
  for (int i = 0; i < h; i++)
    for (int j = 0; j < h; j++) tmp[sx + i][sy + j] = board[ex - j][sy + i];
}

// 십자가 반시계 90도 회전 + 4분할 후 각자 시계 90도 회전
void rotate() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) copied[i][j] = board[j][n - i - 1];
  copy(copied, tmp);

  part_rotate(0, 0, h - 1, h - 1);
  part_rotate(0, h + 1, h - 1, n - 1);
  part_rotate(h + 1, 0, n - 1, h - 1);
  part_rotate(h + 1, h + 1, n - 1, n - 1);
  copy(tmp, board);
}

void init() {
  score = map<pi2, int>();
  group = map<int, vector<pi2> >();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  int round = 4, s = 0;
  while (round--) {
    find_area();
    s += clac_score();
    rotate();
    init();
  }
  cout << s << '\n';
  return 0;
}