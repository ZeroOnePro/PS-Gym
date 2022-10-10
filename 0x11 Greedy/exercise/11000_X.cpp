#include <bits/stdc++.h>

using namespace std;

/**
 * 특정 시각 t에 열리는 수업 수 중 최대값이 정답이다
 * 강의실을 공유할 수 없는 수업 중 최대를 선택하는 문제
 * t의 상한이 십억이기 때문에 모든 시간을 살펴보면 시간초과난다
 */

#define x first
#define y second

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, r = 0, cur = 0, cnt = 0;
  vector<pair<int, int>> c;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int st, en;
    cin >> st >> en;
    c.push_back({st, 1});
    c.push_back({en, -1});
  }
  sort(c.begin(), c.end());
  while (true) {
    int t = c[cur].x;
    while (cur < 2 * n && c[cur].x == t) {
      cnt += c[cur].y;
      cur += 1;
    }
    r = max(r, cnt);
    if (cur == 2 * n) break;
  }
  cout << r;
  return 0;
}