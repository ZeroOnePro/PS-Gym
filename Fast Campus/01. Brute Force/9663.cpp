#include <bits/stdc++.h>

using namespace std;

int n, cnt;
bool is_used[3][40];  // 1차원 열, 2차원 오른 대각, 3차원 왼 대각

void n_queen(int row) {
  // n-1까지 완성
  if (row == n) {
    cnt++;
    return;
  }
  for (int col = 0; col < n; ++col) {
    if (is_used[0][col] or is_used[1][row + col] or
        is_used[2][row - col + n - 1])
      continue;
    is_used[0][col] = true;
    is_used[1][row + col] = true;
    is_used[2][row - col + n - 1] = true;

    n_queen(row + 1);

    is_used[0][col] = false;
    is_used[1][row + col] = false;
    is_used[2][row - col + n - 1] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  n_queen(0);
  cout << cnt;
  return 0;
}