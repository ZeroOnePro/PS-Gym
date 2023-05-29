#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int check(vector<vector<char>> &board, int n) {
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    int cnt = 1;
    for (int j = 1; j < n; ++j) {
      if (board[i][j] == board[i][j - 1]) {
        cnt += 1;
      } else {
        cnt = 1;
      }
      if (ans < cnt)
        ans = cnt;
    }
    cnt = 1;
    for (int j = 1; j < n; ++j) {
      if (board[j][i] == board[j - 1][i]) {
        cnt += 1;
      } else {
        cnt = 1;
      }
      if (ans < cnt)
        ans = cnt;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<char>> board(51, vector<char>(51));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      // 제일 오른쪽열은 안 해도 됨
      if (j + 1 < n) {
        swap(board[i][j], board[i][j + 1]);
        int tmp = check(board, n);
        if (ans < tmp)
          ans = tmp;
        swap(board[i][j], board[i][j + 1]);
      }
      // 제일 아래 행은 안 해도됨
      if (i + 1 < n) {
        swap(board[i][j], board[i + 1][j]);
        int tmp = check(board, n);
        if (ans < tmp)
          ans = tmp;
        swap(board[i][j], board[i + 1][j]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}