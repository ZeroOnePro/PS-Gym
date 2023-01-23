#include <bits/stdc++.h>

using namespace std;

// 구현해야될 것 들
/*
 * 1. 스티커 붙이기 위한 위치 찾는 로직
 * 2. 스티커 회전하는 로직
 * 3. 스티커 칸 수 세는 로직
 */

int n, m, k;
int r, c;
int laptop[42][42];
int sticker[12][12];

// 90도 회전만 구현하면 180과 270은 회전 횟수의 문제
void rotate(void) {
  int rotated[12][12];
  copy(*sticker, *sticker + 144, *rotated);

  for (int col = 0; col < c; ++col) {
    for (int row = 0; row < r; ++row) {
      sticker[col][row] = rotated[r - 1 - row][col];
    }
  }

  swap(r, c);

  return;
}

// 다른 스티커와 겹치지 않으면서 가장 왼쪽 위의 좌표를 반환
bool check(int x, int y) {
  for (int row = 0; row < r; ++row) {
    for (int col = 0; col < c; ++col) {
      if (laptop[x + row][y + col] == 1 and sticker[row][col] == 1)
        return false;
    }
  }
  return true;
}

void put_sticker(int x, int y) {
  for (int row = 0; row < r; ++row) {
    for (int col = 0; col < c; ++col) {
      if (sticker[row][col] == 1) {
        laptop[x + row][y + col] = 1;
      }
    }
  }
  return;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  while (k--) {
    cin >> r >> c;
    for (int row = 0; row < r; ++row) {
      for (int col = 0; col < c; ++col) {
        cin >> sticker[row][col];
      }
    }
    // k개의 각 스티커가 시작 위치를 찾고, 없으면 회전, 회전이 안되면 버린다
    for (int rot = 0; rot < 4; rot++) {
      // 스티커 붙였는지 확인하는 플래그 붙였으면 다음 스티커로
      bool is_put = false;
      for (int row = 0; row <= n - r; row++) {
        if (is_put) break;
        for (int col = 0; col <= m - c; col++) {
          if (check(row, col)) {
            is_put = true;
            put_sticker(row, col);
            break;
          }
        }
      }
      if (is_put) break;
      rotate();
    }
  }
  int cnt = 0;
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < m; ++col) {
      cnt += laptop[row][col] == 1;
    }
  }
  cout << cnt << '\n';
  return 0;
}