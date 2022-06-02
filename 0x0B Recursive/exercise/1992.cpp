#include <bits/stdc++.h>

using namespace std;

string stream[64];
string compressed_video;

bool decision(int n, int row, int col) {
  char target = stream[row][col];
  for (int r = row; r < row + n; ++r) {
    for (int c = col; c < col + n; ++c) {
      if (target != stream[r][c]) return false;
    }
  }
  return true;
}

void compress_video(int n, int row, int col) {
  if (decision(n, row, col)) {
    compressed_video += stream[row][col];
    return;
  }
  int next_step = n / 2;
  // 재귀호출이 필요할 때마다 괄호를 붙여준다.
  compressed_video += "(";
  for (int r = 0; r < 2; ++r) {
    for (int c = 0; c < 2; ++c) {
      compress_video(next_step, row + r * next_step, col + c * next_step);
    }
  }
  compressed_video += ")";
  return;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int row = 0; row < n; ++row) cin >> stream[row];
  compress_video(n, 0, 0);
  cout << compressed_video;
  return 0;
}