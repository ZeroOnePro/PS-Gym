#include <bits/stdc++.h>

using namespace std;

const int range = 15;

int n, tot;
bool debug = false;

pair<int, int> board[range][range];

void print() {
  cout << '\n';
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) cout << board[i][j].first << ' ';
    cout << '\n';
  }
}

// 행이나 열이 제거되고 나면 이전 행과 열 땡기는 함수
// 제거되는 행이나 열 번호 가지고 있으면 그대로 평행이동해주기(복사) => 그게
// 안되는게 삭제된 행 밑에 빈 칸있을 수 있음 st는 제거되기 시작하는 행이나 열의
// 인덱스, area는 영역의 번호(0은 파랑, 1은 초록)
// 이거 블럭 모양에 따라 내려가는거도 다르다 2x1, 1x2, 1x1
// 블럭의 타입과 아이디를 이용해서 쌍을 찾아주고 같이 움직이기
void relocate(int st, int area) {
  // 파랑 영역
  if (area == 0) {
    for (int row = 0; row < 4; ++row) {
      int cur = st;
      // st부터 오른쪽로 빈칸이 어디까지 있는지 찾기
      // 여기서 블록 모양에 따라 다르게 땡겨야한다
      while (cur < 10 && board[row][cur].first == 0) cur += 1;
      cur -= 1;
      // st왼쪽 블록을 찾아서 cur로 땡기기
      for (int col = st - 1; col >= 4; --col)
        if (board[row][col].first) {
          board[row][cur--] = board[row][col];
          board[row][col] = {0, 0};
        }
    }
  }
  // 초록 영역
  else {
    for (int col = 0; col < 4; ++col) {
      int cur = st;
      // st부터 아래로 빈칸이 어디까지 있는지 찾기
      while (cur < 10 && board[cur][col].first == 0) cur += 1;
      cur -= 1;
      // st위에 있는 블록을 찾아서 cur로 땡기기
      // 여기서 블록 모양에 따라 다르게 땡겨야한다
      for (int row = st - 1; row >= 4; --row)
        if (board[row][col].first) {
          board[cur--][col] = board[row][col];
          board[row][col] = {0, 0};
        }
    }
  }
}

// 블록 제거
// 특별 영역은 제외
// 파랑 영역은 6 ~ 9열까지 보면서 꽉찬 열있는지 검사(0 ~ 3행)
// 초록 영역은 6 ~ 9행까지 보면서 꽉찬 행있는지 검사(0 ~ 3열)
// 최종적으로 제거되는 열과 행의 개수가 점수가 된다
// 해당 행과 열 제거하고 이전 행과 열 땡기기 구현하기
// 땡기고 나서 또 꽉차는 것 있는지 본 뒤에 제거하고 꽉차는 것 없어질 때까지 반복
int check_normal_area() {
  int score = 0;
  // 파란 영역의 꽉찬 열 제거
  while (true) {
    vector<int> full_col;
    for (int col = 0; col < 4; ++col) {
      bool is_full = true;
      for (int row = 0; row < 4; ++row)
        is_full &= (board[row][col + 6].first != 0);
      if (is_full) full_col.push_back(col + 6);
    }
    if (full_col.size() == 0) break;
    for (int col : full_col)
      for (int row = 0; row < 4; ++row) board[row][col] = {0, 0};
    relocate(full_col.back(), 0);
    score += full_col.size();
  }
  // 초록 영역의 꽉찬 행 제거
  while (true) {
    vector<int> full_row;
    for (int row = 0; row < 4; ++row) {
      bool is_full = true;
      for (int col = 0; col < 4; ++col)
        is_full &= (board[row + 6][col].first != 0);
      if (is_full) full_row.push_back(row + 6);
    }
    if (full_row.size() == 0) break;
    for (int row : full_row)
      for (int col = 0; col < 4; ++col) board[row][col] = {0, 0};
    relocate(full_row.back(), 1);
    score += full_row.size();
  }
  return score;
}

// 특별 영역에 블록이 위치하는지 본다
// 파랑 영역은 4 ~ 5열에 블록이 있는지 검사(0 ~ 3행)
// 초록 영역은 4 ~ 5행에 블록이 있는지 검사(0 ~ 3열)
// 파랑 영역 기준으로
// 5열에 블록이 있다면 9열에 있는 모든 블록 제거
// 제거 후 꽉차는 열이나 행은 없다, normal area의 처리가 선행되기 때문
// 4, 5열에 블록이 모두 있다면 8, 9열에 있는 모든 블록 제거(덮어쓰기)
int check_special_area() {
  // 파랑영역
  int cnt = 0, score = 0;
  for (int col = 4; col <= 5; ++col) {
    bool is_exist = false;
    for (int row = 0; row < 4; ++row) is_exist |= (board[row][col].first != 0);
    if (is_exist) cnt += 1;
  }
  if (cnt > 0) {
    for (int row = 0; row < 4; ++row)
      for (int col = 9; col > 9 - cnt; --col) board[row][col] = {0, 0};
    relocate(9, 0);
  }
  score += cnt;
  cnt = 0;
  // 초록 영역
  for (int row = 4; row <= 5; ++row) {
    bool is_exist = false;
    for (int col = 0; col < 4; ++col) is_exist |= (board[row][col].first != 0);
    if (is_exist) cnt += 1;
  }
  if (cnt > 0) {
    for (int col = 0; col < 4; ++col)
      for (int row = 9; row > 9 - cnt; --row) board[row][col] = {0, 0};
    relocate(9, 1);
  }
  score += cnt;
  return cnt;
}

// 1x1 이동시키는 함수
int move(int x, int y, int area) {
  int cur;
  // 파랑으로 이동
  if (area == 0) {
    cur = y;
    while (cur < 10 && board[x][cur].first == 0) cur += 1;
  }
  // 초록으로 이동
  else {
    cur = x;
    while (cur < 10 && board[cur][y].first == 0) cur += 1;
  }
  return cur - 1;
}

// 블록을 맵에 놓고 파랑영역과 초록영역으로 이동
// t는 놓는 블록의 타입 x, y는 각각 시작좌표의 행과 열
// 1x2, 2x1의 경우 더 먼저 멈추는 거(min) 기준으로 변경
void put_move(int t, int id, int x, int y) {
  int cur;
  // 1x1
  if (t == 1) {
    cur = move(x, y, 0);
    board[x][cur] = {1, id};
    cur = move(x, y, 1);
    board[cur][y] = {1, id};
  }
  // 1x2
  else if (t == 2) {
    for (int i = 0; i <= 1; ++i) {
      cur = move(x, y + i, 0);
      board[x][cur] = {2, id};
    }
    cur = min(move(x, y + 1, 1), move(x, y, 1));
    board[cur][y] = {2, id};
    board[cur][y + 1] = {2, id};
  }
  // 2x1
  else {
    cur = min(move(x + 1, y, 0), move(x, y, 0));
    board[x][cur] = {3, id};
    board[x + 1][cur] = {3, id};
    for (int i = 1; i >= 0; --i) {
      cur = move(x + i, y, 1);
      board[cur][y] = {3, id};
    }
  }
}

// 이동 후 normal_area 검사와 special_area 검사가 순차적으로 이뤄진 후 점수 계산
void simulation(int t, int id, int x, int y) {
  put_move(t, id, x, y);
  tot += check_normal_area();
  tot += check_special_area();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    simulation(t, i, x, y);
    print();
  }
  cout << tot;
  return 0;
}