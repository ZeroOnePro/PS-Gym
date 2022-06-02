#include <bits/stdc++.h>

using namespace std;

int counts[3];
int paper[2189][2189];

bool decision(int n, int row, int col) {
  int target = paper[row][col];
  for (int r = row; r < row + n; ++r) {
    for (int c = col; c < col + n; ++c) {
      if (target != paper[r][c]) return false;
    }
  }
  return true;
}

void cut_paper(int n, int row, int col) {
  if (decision(n, row, col)) {
    counts[paper[row][col] + 1] += 1;
    return;
  }
  int next_step = n / 3;
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      // 체크할 영역의 시작점에 대해 재귀함수를 돌린다.
      // 임의의 n에 대해여 체크할 영역이 9개로 분할되니 9개의 시작점이 생긴다.
      cut_paper(next_step, row + r * next_step, col + c * next_step);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < n; ++col) {
      cin >> paper[row][col];
    }
  }
  cut_paper(n, 0, 0);
  for (int i = 0; i < 3; ++i) cout << counts[i] << '\n';
  return 0;
}