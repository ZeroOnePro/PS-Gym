#include <bits/stdc++.h>

using namespace std;

const int range = 105;

int square[range][range];
int csquare[range][range];

int rotate(int sx, int sy, int ex, int ey) {
  int mn = 10'005;
  copy(*square, *square + range * range, *csquare);
  // 윗변 이동
  for (int i = sy; i < ey; ++i) {
    csquare[sx][i + 1] = square[sx][i];
    mn = min(mn, square[sx][i]);
  }
  csquare[sx + 1][ey] = square[sx][ey];
  mn = min(mn, square[sx][ey]);
  // 우변 이동
  for (int i = sx + 1; i < ex; ++i) {
    csquare[i + 1][ey] = square[i][ey];
    mn = min(mn, square[i][ey]);
  }
  csquare[ex][ey - 1] = square[ex][ey];
  mn = min(mn, square[ex][ey]);
  // 아랫변 이동
  for (int i = ey - 1; i > sy; --i) {
    csquare[ex][i - 1] = square[ex][i];
    mn = min(mn, square[ex][i]);
  }
  csquare[ex - 1][sy] = square[ex][sy];
  mn = min(mn, square[ex][sy]);
  // 좌변 이동
  for (int i = ex - 1; i > sx; --i) {
    csquare[i - 1][sy] = square[i][sy];
    mn = min(mn, square[i][sy]);
  }
  copy(*csquare, *csquare + range * range, *square);
  return mn;
}

void print(int rows, int cols) {
  cout << '\n';
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= cols; ++j)
      cout << setfill('0') << setw(2) << square[i][j] << ' ';
    cout << '\n';
  }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  vector<int> answer;
  int elem = 1;
  for (int i = 1; i <= rows; ++i)
    for (int j = 1; j <= columns; ++j) square[i][j] = elem++;
  for (vector<int> q : queries) {
    int sx = q[0], sy = q[1], ex = q[2], ey = q[3];
    answer.push_back(rotate(sx, sy, ex, ey));
  }
  return answer;
}