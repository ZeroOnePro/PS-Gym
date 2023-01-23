#include <bits/stdc++.h>

using namespace std;

const int range = 45;

int n, m, k;
int st_x, st_y;  // 스티커의 시작위치

/**
 * 틀린 이유
 * 1. 스티커를 붙일 수 있는 시작점 검사 범위를 [0,n) [0,m)로 했었음
 * 2. 배열 회전하는 코드 잘못 작성했었음
 */

// 각 스티커마다 회전한거 미리 저장
// 스티커 1 => 0, 90, 180, 270 이런식으로
vector<vector<vector<int>>> sticker[105];
int laptop[range][range];

pair<int, int> clac_size(vector<vector<int>> v) {
  return {v.size(), v[0].size()};
}

// 스티커 90도 회전시키기
vector<vector<int>> rotate_90(vector<vector<int>> v) {
  auto [r, c] = clac_size(v);
  vector<vector<int>> rotate(c, vector<int>(r, 0));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      rotate[j][r - i - 1] = v[i][j];
    }
  }
  return rotate;
}

// 스티커 붙일 수 있는지 확인
// 회전된 거 붙일 수 있는지 판단 => 범위 벗어나는지?, 겹치는지?
// x, y는 붙일 시작위치, v는 스티커
bool check(int x, int y, vector<vector<int>> v) {
  auto [r, c] = clac_size(v);
  for (int row = 0; row < r; ++row)
    for (int col = 0; col < c; ++col) {
      if (x + row >= n || y + col >= m) return false;
      if (laptop[x + row][y + col] == 1 && v[row][col] == 1) return false;
    }
  return true;
}

// 스티커 시작 위치 찾기
// 가장 위쪽부터, 위쪽이 여러개라면 가장 왼쪽
bool find_st(vector<vector<int>> v) {
  auto [r, c] = clac_size(v);
  for (int row = 0; row <= n - r; row++) {
    for (int col = 0; col <= m - c; col++) {
      if (check(row, col, v)) {
        st_x = row;
        st_y = col;
        return true;
      }
    }
  }
  return false;
}

// 스티커 붙이기
// x, y는 붙일 시작위치, v는 스티커
void mark(int x, int y, vector<vector<int>> v) {
  auto [r, c] = clac_size(v);
  for (int row = 0; row < r; ++row)
    for (int col = 0; col < c; ++col)
      if (v[row][col] == 1) laptop[x + row][y + col] = 1;
}

// 스티커 개수 세기
int count_sticker() {
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cnt += (laptop[i][j] == 1);
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> s(r, vector<int>(c, 0));
    for (int row = 0; row < r; ++row)
      for (int col = 0; col < c; ++col) cin >> s[row][col];
    sticker[i].push_back(s);
    // 배열 회전 90, 180, 270
    for (int j = 0; j < 3; ++j) sticker[i].push_back(rotate_90(sticker[i][j]));
  }
  // 스티커 붙이기
  for (int i = 0; i < k; ++i) {
    // 4종류의 스티커(0, 90, 180, 270)를 붙일 수 있는지 확인
    for (int j = 0; j < 4; ++j) {
      vector<vector<int>> s = sticker[i][j];
      if (find_st(s)) {
        mark(st_x, st_y, s);
        break;
      }
    }
  }
  cout << count_sticker();
  return 0;
}