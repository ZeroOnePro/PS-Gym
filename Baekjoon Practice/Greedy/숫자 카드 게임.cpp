#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// 반성할 점: 이런 문제는 입력단에서 처리해버리면 두 번일 안생긴다.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> cards(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> cards[i][j];
    }
  }
  int ans = *min_element(cards[0].begin(), cards[0].end());
  ;
  for (int i = 1; i < n; ++i) {
    ans = max(ans, *min_element(cards[i].begin(), cards[i].end()));
  }
  std::cout << ans << '\n';
  return 0;
}