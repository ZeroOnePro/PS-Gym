#include <bits/stdc++.h>

using namespace std;

char board[6561][6561];

void draw_stars(int n, int row, int col) {
  if (n == 1) {
    board[row][col] = '*';
    return;
  }
  int next_step = n / 3;
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      if (r == 1 and c == 1) continue;
      draw_stars(next_step, row + r * next_step, col + c * next_step);
    }
  }
}

void print_starts(int n) {
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < n; ++col) {
      cout << board[row][col];
    }
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) fill(board[i], board[i] + n - 1, ' ');
  draw_stars(n, 0, 0);
  print_starts(n);
  return 0;
}