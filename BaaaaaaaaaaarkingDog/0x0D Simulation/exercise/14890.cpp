#include <bits/stdc++.h>

using namespace std;

const int range = 105;

int n, l;
int s[range][range];
bool vis[range][range];  // 사다리 겹침 피하기 위해 놓은 공간 마킹

int up_down() {
  int cnt = 0;
  for (int col = 0; col < n; ++col) {
    bool is_possible = true;
    for (int i = 0; i < n - 1; ++i) {
      int j = i + 1;
      if (s[i][col] < s[j][col]) {
        if (s[j][col] - s[i][col] > 1) {
          is_possible = false;
          break;
        } else {
          int height = s[i][col];
          if (i - l + 1 < 0) {
            is_possible = false;
            break;
          }
          for (int k = i; k >= i - l + 1; --k) {
            if (vis[k][col] || height != s[k][col]) {
              is_possible = false;
              for (int t = k; t <= i; ++t) vis[t][col] = false;
              break;
            }
            vis[k][col] = true;
          }
        }
      } else if (s[i][col] > s[j][col]) {
        if (s[i][col] - s[j][col] > 1) {
          is_possible = false;
          break;
        } else {
          int height = s[j][col];
          if (j + l - 1 >= n) {
            is_possible = false;
            break;
          }
          for (int k = j; k <= j + l - 1; ++k) {
            if (vis[k][col] || height != s[k][col]) {
              is_possible = false;
              for (int t = j; t <= k; ++t) vis[t][col] = false;
              break;
            }
            vis[k][col] = true;
          }
        }
      }
    }
    if (is_possible) cnt += 1;
  }
  return cnt;
}

int left_right() {
  int cnt = 0;
  for (int row = 0; row < n; ++row) {
    bool is_possible = true;
    for (int i = 0; i < n - 1; ++i) {
      int j = i + 1;
      if (s[row][i] < s[row][j]) {
        if (s[row][j] - s[row][i] > 1) {
          is_possible = false;
          break;
        } else {
          int height = s[row][i];
          if (i - l + 1 < 0) {
            is_possible = false;
            break;
          }
          for (int k = i; k >= i - l + 1; --k) {
            if (vis[row][k] || height != s[row][k]) {
              is_possible = false;
              for (int t = k; t <= i; ++t) vis[row][t] = false;
              break;
            }
            vis[row][k] = true;
          }
        }
      } else if (s[row][i] > s[row][j]) {
        if (s[row][i] - s[row][j] > 1) {
          is_possible = false;
          break;
        } else {
          int height = s[row][j];
          if (j + l - 1 >= n) {
            is_possible = false;
            break;
          }
          for (int k = j; k <= j + l - 1; ++k) {
            if (vis[row][k] || height != s[row][k]) {
              is_possible = false;
              for (int t = j; t <= k; ++t) vis[row][t] = false;
              break;
            }
            vis[row][k] = true;
          }
        }
      }
    }
    if (is_possible) cnt += 1;
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> l;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> s[i][j];
  // 상하방향 길 검사
  int sum = up_down();
  for (int i = 0; i < n; ++i) fill(vis[i], vis[i] + n, false);
  // 좌우방향 길 검사
  sum += left_right();
  cout << sum;
  return 0;
}