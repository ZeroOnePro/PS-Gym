#include <bits/stdc++.h>

using namespace std;

char board[3074][6145];

void print_starts(int n) {
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < 2 * n - 1; ++col) {
      cout << board[row][col];
    }
    cout << '\n';
  }
}

void draw_stars(int n, int row, int col) {
  if (n == 3) {
    board[row][col] = '*';
    board[row + 1][col - 1] = '*';
    board[row + 1][col + 1] = '*';
    for (int i = -2; i <= 2; ++i) board[row + 2][col + i] = '*';
    return;
  }
  int next_step = n / 2;
  draw_stars(next_step, row, col);
  draw_stars(next_step, row + next_step, col - next_step);
  draw_stars(next_step, row + next_step, col + next_step);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) fill(board[i], board[i] + 2 * n - 1, ' ');
  // 처음에 주어주는 시작점 부터 재귀적으로 다음 스텝의 시작점이 어떻게
  // 구성되는지 생각해야한다.
  draw_stars(n, 0, n - 1);
  print_starts(n);
  return 0;
}