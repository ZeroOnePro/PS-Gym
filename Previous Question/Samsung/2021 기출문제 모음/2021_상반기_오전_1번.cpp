#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n;
int board[range][range];
queue<int> q;
map<int, set<int>> table;

void input() {
  cin >> n;
  for (int i = 0; i < n * n; ++i) {
    int from, to;
    cin >> from;
    q.push(from);
    for (int j = 0; j < 4; ++j) {
      cin >> to;
      table[from].insert(to);
    }
  }
}

/**
 * @brief 학생 번호가 주어졌을 때 해당 학생이 들어가는 좌표 정하기
 *
 * 1. 격자를 벗어나지 않는 4방향으로 인접한 칸 중 앉아있는 좋아하는 친구의 수가
 * 가장 많은 위치로 갑니다.
 *
 * 2. 만약 1번 조건을 만족하는 칸의 위치가 여러 곳이라면,
 * 그 중 인접한 칸 중 비어있는 칸의 수가 가장 많은 위치로 갑니다. 단 이때 격자를
 * 벗어나는 칸은 비어있는 칸으로 간주하지 않습니다.
 *
 * 3. 만약 2번 조건까지 동일한 위치가 여러 곳이라면, 그 중 행 번호가 가장 작은
 * 위치로 갑니다.
 *
 * 4. 만약 3번 조건까지 동일한 위치가 여러 곳이라면, 그 중 열 번호가 가장 작은
 * 위치로 갑니다.
 *
 */
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

bool compare(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
  if (get<0>(a) == get<0>(b)) {
    if (get<1>(a) == get<1>(b)) {
      if (get<2>(a) == get<2>(b)) return get<3>(a) <= get<3>(b);
      return get<2>(a) < get<2>(b);
    }
    return get<1>(a) > get<1>(b);
  }
  return get<0>(a) > get<0>(b);
}

void find_location(int num) {
  vector<tuple<int, int, int, int>> info;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (board[i][j] != 0) continue;
      int ff = 0, empty = 0;
      for (int dir = 0; dir < 4; ++dir) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (OOB(nx, ny)) continue;
        if (board[nx][ny] == 0) empty += 1;
        if (table[num].find(board[nx][ny]) != table[num].end()) ff += 1;
      }
      info.push_back({ff, empty, i, j});
    }
  sort(info.begin(), info.end(), compare);
  int x = get<2>(info[0]), y = get<3>(info[0]);
  board[x][y] = num;
}

int clac_score() {
  int score = 0;
  int rule[] = {0, 1, 10, 100, 1000};
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int ff = 0;
      for (int dir = 0; dir < 4; ++dir) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (OOB(nx, ny)) continue;
        if (table[board[i][j]].find(board[nx][ny]) != table[board[i][j]].end())
          ff += 1;
      }
      score += rule[ff];
    }
  return score;
}

void print() {
  cout << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << board[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  while (!q.empty()) {
    int num = q.front();
    q.pop();
    find_location(num);
  }
  cout << clac_score();
  return 0;
}