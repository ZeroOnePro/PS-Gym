#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_case;
  cin >> test_case;
  int n, m, x, y;
  while (test_case--) {
    cin >> m >> n >> x >> y;
    bool possible_combination = false;
    int year;
    int mx = lcm(m, n);
    if (x == m) x = 0;
    if (y == n) y = 0;
    // 입력 크기를 보면 1부터 시작하면 시간초과가 난다
    // 구하고자 하는 해의 범위를 줄인다
    // 구하고자 하는 해가 m으로 나눴을 때 나머지가 x인 수들을 대상으로 n으로
    // 나눴을 때 나머지가 n인지 검사한다 최대 lcm(m, n) / m만큼 걸린다
    // 하나의 범위를 정해놓고 나머지의 탐색범위를 줄이는 방법으로 접근하였음
    for (int i = x; i <= mx; i += m) {
      if (i == 0) continue;
      if (i % n == y) {
        possible_combination = true;
        year = i;
        break;
      }
    }
    cout << (possible_combination ? year : -1) << '\n';
  }
  return 0;
}