#include <bits/stdc++.h>

using namespace std;

int counts[2];
int paper[130][130];

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
    counts[paper[row][col]] += 1;
    return;
  }
  int next_step = n / 2;
  for (int r = 0; r < 2; ++r) {
    for (int c = 0; c < 2; ++c) {
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
  for (int i = 0; i < 2; ++i) cout << counts[i] << '\n';
  return 0;
}