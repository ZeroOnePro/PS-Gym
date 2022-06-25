#include <bits/stdc++.h>

using namespace std;

/* 구현해야하는 것 */
/*
 * 1. 상하좌우 이동하기
 * 2. 각 방향 조합 수 계산
 */

int n;
int board[22][22];
int copied_board[22][22];

void rotate(void) {
  int rotated[22][22];
  copy(*copied_board, *copied_board + 22 * 22, *rotated);
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < n; ++col) {
      copied_board[row][col] = rotated[n - 1 - col][row];
    }
  }
}

void game(int dir) {
  while (dir--) rotate();
  for (int row = 0; row < n; ++row) {
    int moved[22] = {};
    int idx = 0;
    for (int col = 0; col < n; ++col) {
      if (copied_board[row][col] == 0) continue;
      if (moved[idx] == 0)
        moved[idx] = copied_board[row][col];
      else if (moved[idx] == copied_board[row][col])
        moved[idx++] *= 2;
      else
        moved[++idx] = copied_board[row][col];
    }
    copy(moved, moved + 22, copied_board[row]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int maximum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
    }
  }
  for (int i = 0; i < (1 << 10); ++i) {
    copy(*board, *board + 22 * 22, *copied_board);
    int cs = i;
    for (int j = 0; j < 5; ++j) {
      int dir = cs % 4;
      cs /= 4;
      game(dir);
    }
    for (int i = 0; i < n; ++i)
      maximum =
          max(maximum, *max_element(copied_board[i], copied_board[i] + 22));
  }
  cout << maximum;
  return 0;
}