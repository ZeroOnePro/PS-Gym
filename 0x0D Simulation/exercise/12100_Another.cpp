#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int range = 25;

int n, mx = 0;

int seq[5];
// (원소, 합쳐짐 여부)
pii origin[range][range];
pii board[range][range];

// 1. 블록 합치기
// 밀고 난 후라 바로 인접한 것만 합칠 수 있는지 검사하고 합치고
// 빈 공간 생기면 땡겨주기
// 땡기면 인접 관계가 사라질 수 있음
void concat(int dir) {
  switch (dir) {
    // 위로 합치기
    case 0:
      for (int col = 0; col < n; ++col)
        for (int row = 0; row < n; ++row)
          for (int i = row + 1; i < n; ++i) {
            if (board[i][col].x != 0 && board[i][col].x != board[row][col].x)
              break;
            if (board[i][col].x == board[row][col].x && !board[i][col].y &&
                !board[row][col].y) {
              board[row][col].x *= 2;
              board[row][col].y = true;
              board[i][col].x = 0;
            }
          }
      break;
    // 아래로 합치기
    case 1:
      for (int col = 0; col < n; ++col)
        for (int row = n - 1; row >= 0; --row)
          for (int i = row - 1; i >= 0; --i) {
            if (board[i][col].x != 0 && board[i][col].x != board[row][col].x)
              break;
            if (board[i][col].x == board[row][col].x && !board[i][col].y &&
                !board[row][col].y) {
              board[row][col].x *= 2;
              board[row][col].y = true;
              board[i][col].x = 0;
            }
          }
      break;
    // 좌로 합치기
    case 2:
      for (int row = 0; row < n; ++row)
        for (int col = 0; col < n; ++col)
          for (int i = col + 1; i < n; ++i) {
            if (board[row][i].x != 0 && board[row][i].x != board[row][col].x)
              break;
            if (board[row][col].x == board[row][i].x && !board[row][i].y &&
                !board[row][col].y) {
              board[row][col].x *= 2;
              board[row][col].y = true;
              board[row][i].x = 0;
              break;
            }
          }
      break;
    // 우로 합치기
    case 3:
      for (int row = 0; row < n; ++row)
        for (int col = n - 1; col >= 0; --col)
          for (int i = col - 1; i >= 0; --i) {
            if (board[row][i].x != 0 && board[row][i].x != board[row][col].x)
              break;
            if (board[row][col].x == board[row][i].x && !board[row][i].y &&
                !board[row][col].y) {
              board[row][col].x *= 2;
              board[row][col].y = true;
              board[row][i].x = 0;
              break;
            }
          }
      break;
  }
}

// 2. 블록 이동하기
void move(int dir) {
  switch (dir) {
    // 위로 밀기
    case 0:
      for (int col = 0; col < n; ++col)
        for (int row = 0; row < n; ++row)
          for (int i = row + 1; i < n; ++i)
            // 빈공간을 만나면 아래로 가다가 제일 처음만난 블록 현재 위치로
            if (board[row][col].x == 0 && board[i][col].x) {
              swap(board[i][col], board[row][col]);
              break;
            }
      break;
    // 아래로 밀기
    case 1:
      for (int col = 0; col < n; ++col)
        for (int row = n - 1; row >= 0; --row)
          for (int i = row - 1; i >= 0; --i)
            if (board[row][col].x == 0 && board[i][col].x) {
              swap(board[i][col], board[row][col]);
              break;
            }
      break;
    // 좌로 밀기
    case 2:
      for (int row = 0; row < n; ++row)
        for (int col = 0; col < n; ++col)
          for (int i = col + 1; i < n; ++i)
            if (board[row][col].x == 0 && board[row][i].x) {
              swap(board[row][i], board[row][col]);
              break;
            }
      break;
    // 우로 밀기
    case 3:
      for (int row = 0; row < n; ++row)
        for (int col = n - 1; col >= 0; --col)
          for (int i = col - 1; i >= 0; --i)
            if (board[row][col].x == 0 && board[row][i].x) {
              swap(board[row][i], board[row][col]);
              break;
            }
      break;
  }
}

int clac_mx() {
  int local_mx = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) local_mx = max(local_mx, board[i][j].x);
  return local_mx;
}

void init() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) board[i][j].y = false;
}

// 3. 이동 조합의 경우 생성
void all_case(int cur) {
  if (cur == 5) {
    copy(*origin, *origin + range * range, *board);
    // 여기서 move, concat
    // 틀린이유? 이동 한 번 시키면, 합쳤던 것 여부 초기화 해줘야하나본데?
    for (int dir : seq) {
      move(dir);
      concat(dir);
      move(dir);
      init();
    }
    mx = max(clac_mx(), mx);
    return;
  }
  for (int i = 0; i < 4; ++i) {
    seq[cur] = i;
    all_case(cur + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int elem;
      cin >> elem;
      origin[i][j] = {elem, false};
    }
  all_case(0);
  cout << mx;
  return 0;
}