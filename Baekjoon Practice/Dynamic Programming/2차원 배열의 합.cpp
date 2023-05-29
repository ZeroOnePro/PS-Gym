#include <iostream>
#include <vector>

using namespace std;
int matrix[301][301];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int i, j, x, y, n, m, k;
  cin >> n >> m;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      cin >> matrix[r][c];
    }
  }
  cin >> k;
  for (int t = 0; t < k; ++t) {
    cin >> i >> j >> x >> y;
    i--;
    j--;
    x--;
    y--;
    // col by col
    int sum = 0;
    for (int c = j; c <= y; ++c) {
      for (int r = i; r <= x; ++r) {
        sum += matrix[r][c];
      }
    }
    cout << sum << '\n';
  }
  return 0;
}