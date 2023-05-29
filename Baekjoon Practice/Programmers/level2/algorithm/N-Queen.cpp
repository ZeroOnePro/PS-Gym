#include <bits/stdc++.h>

using namespace std;

int cnt;
bool is_used[3][30];

void n_queen(int row, int n) {
  if (row == n) {
    cnt++;
    return;
  }
  for (int col = 0; col < n; ++col) {
    if (is_used[0][col] || is_used[1][row + col] ||
        is_used[2][row - col + n - 1])
      continue;
    is_used[0][col] = is_used[1][row + col] = is_used[2][row - col + n - 1] =
        true;
    n_queen(row + 1, n);

    is_used[0][col] = is_used[1][row + col] = is_used[2][row - col + n - 1] =
        false;
  }
}

int solution(int n) {
  n_queen(0, n);
  int answer = cnt;
  return answer;
}