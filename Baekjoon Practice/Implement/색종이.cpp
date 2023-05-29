#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<vector<bool>> map(101, vector<bool>(101, false));

  // 좌표평면을 만들고 입력된 좌표를 기준으로 만들어진 사각형은 모두 true로
  // 만든다.
  int n;
  cin >> n;
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    for (int r = x; r < x + 10; ++r) {
      for (int c = y; c < y + 10; ++c) {
        map[r][c] = true;
      }
    }
  }
  int surface = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      map[i][j] ? surface += 1 : surface = surface;
    }
  }
  cout << surface << '\n';
  return 0;
}