#include <bits/stdc++.h>

using namespace std;

int n;
int board[15][15];
bool is_used[2][105];
enum Color { WHITE, BLACK };
int ans[2];
int cnt;

/**
 * 모든 자리에 놓아보고 최대 찾기
 * 해당 자리에 놓을거라고 선택하면 좌우대각은 사용 불가능
 */

void bishop(int row, int col, int color) {
  if (col >= n) {
    row += 1;
    col = col & 1 ? 0 : 1;
  }
  if (row >= n) {
    ans[color] = max(ans[color], cnt);
    return;
  }
  // 1. (row, col) 선택
  if (board[row][col] != 0 && !is_used[0][row + col] &&
      !is_used[1][row - col + n - 1]) {
    is_used[0][row + col] = true;
    is_used[1][row - col + n - 1] = true;
    cnt += 1;
    bishop(row, col + 2, color);
    cnt -= 1;
    is_used[0][row + col] = false;
    is_used[1][row - col + n - 1] = false;
  }
  // 2. (row, col) 미선택
  bishop(row, col + 2, color);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
    }
  }
  bishop(0, 0, WHITE);
  bishop(0, 1, BLACK);
  cout << ans[WHITE] + ans[BLACK] << '\n';
  return 0;
}