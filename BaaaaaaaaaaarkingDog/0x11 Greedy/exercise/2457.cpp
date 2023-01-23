#include <bits/stdc++.h>

using namespace std;

/**
 * 탐욕 기준
 *
 * 선택지가 여러개라면 가장 기간이 긴 것 선택
 *
 */

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> flower;
  for (int i = 0; i < n; ++i) {
    int sm, sd, em, ed;
    cin >> sm >> sd >> em >> ed;
    flower.push_back({sm * 100 + sd, em * 100 + ed});
  }
  int st = 301;
  int ans = 0;
  int i = 0;
  // 시작일이 빠른 순 같다면 끝나는날이 빠른 순으로 정렬
  // 시작일이 같으면 더 늦게 끝나는 순
  sort(flower.begin(), flower.end());
  while (st < 1201) {
    int en = st;
    // 선택할 수 있는 것들 중 제일 늦게 끝나는 것 찾을 때까지
    while (i < n && flower[i].first <= st) {
      if (flower[i].second > en) en = flower[i].second;
      i += 1;
    }
    // 선택할 꽃이 없음
    if (st == en) {
      cout << 0;
      return 0;
    }
    ans++;
    st = en;
  }
  cout << ans;
  return 0;
}