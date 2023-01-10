#include <bits/stdc++.h>

using namespace std;

#define v3i vector<vector<vector<int>>>
#define v2i vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>

const int range = 505;

// 테트로미노의 모양을 미리 정의
// 이거 말고 다른 방법은
// dfs 탐색 방향 달리해줘서 depth가 크기가 될 때까지
// 탐색하면 모든 모양이 나올 수 있을까?
v3i tetromino = {{{1, 1, 1, 1}},
                 {{1, 1}, {1, 1}},
                 {{1, 0}, {1, 0}, {1, 1}},
                 {{1, 0}, {1, 1}, {0, 1}},
                 {{1, 1, 1}, {0, 1, 0}}};

int n, m, mx = -1;
int board[range][range];

pii clac_size(v2i v) { return {v.size(), v[0].size()}; }

/**
 * 회전과 대칭에 관한 관찰
 * 시계방향 회전과 y축 대칭의 조합만 있으면 되나?
 * 반시계 방향은 필요 없음? 상관없다, 왜냐하면 시계와 반시계는 만들어지는 순서만
 * 다를 뿐 같다
 * x축 대칭은 필요 없음? 상관없다, y축만 하면 된다, 같은 모양이 중복되기 때문
 */

// y축 대칭
v2i y_symmetry(v2i v) {
  auto [r, c] = clac_size(v);
  v2i s(r, vi(c, 0));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      s[i][c - j - 1] = v[i][j];
    }
  }
  return s;
}

v2i rotate(int dir, v2i v) {
  v2i prev = v;
  for (int i = 0; i < dir; ++i) {
    auto [r, c] = clac_size(prev);
    v2i rotate(c, vi(r, 0));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        rotate[j][r - i - 1] = prev[i][j];
      }
    }
    prev = rotate;
  }
  return prev;
}

int clac_sum(int row, int col, v2i v) {
  int sum = 0;
  auto [r, c] = clac_size(v);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (v[i][j] == 1) sum += board[row + i][col + j];
  return sum;
}

// 테트로미노를 내려놓는 함수
// max안 쓰고 클 때만 대입시키는 상수최적화 시도해볼 수 있겠다
void put(v2i v) {
  auto [r, c] = clac_size(v);
  for (int row = 0; row <= n - r; row++)
    for (int col = 0; col <= m - c; col++) mx = max(mx, clac_sum(row, col, v));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> board[i][j];

  // 5개의 테트로미노에 대해서
  for (int i = 0; i < 5; ++i) {
    v2i cur = tetromino[i];
    // 8개의 가능한 경우에 대해서 검사
    put(cur);
    put(y_symmetry(cur));
    for (int j = 1; j < 4; ++j) {
      v2i tmp = rotate(j, cur);
      put(tmp);
      put(y_symmetry(tmp));
    }
  }
  cout << mx;

  return 0;
}