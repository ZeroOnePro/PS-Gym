#include <bits/stdc++.h>

using namespace std;

const int range = 50;

int n = 5;
int mid = n / 2;
int board[range][range];
int tmp[range][range];

void copy() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) board[i][j] = tmp[i][j];
}

void rotate_clock_90() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) tmp[j][n - 1 - i] = board[i][j];
  copy();
}

void rotate_counter_clock_90() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) tmp[n - 1 - j][i] = board[i][j];
  copy();
}

void rotate_clock_90_part_area(int x, int y) {
  for (int i = 0; i < mid; ++i)
    for (int j = 0; j < mid; ++j)
      tmp[x + j][y + mid - i - 1] = board[x + i][y + j];
  copy();
}

void rotate_counter_clock_90_part_area(int x, int y) {
  for (int i = 0; i < mid; ++i)
    for (int j = 0; j < mid; ++j)
      tmp[x + mid - j - 1][y + i] = board[x + i][y + j];
  copy();
}

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << setw(2) << board[i][j] << ' ';
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int elem = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) board[i][j] = elem++;
  rotate_counter_clock_90_part_area(0, mid + 1);
  print();
  return 0;
}