#include <bits/stdc++.h>

using namespace std;

int n, m, l;
vector<int> rest;

bool possible(int x) {
  if (x == 0) return true;
  int cnt = 0;
  for (int i = 1; i <= n + 1; ++i) {
    int dist = rest[i] - rest[i - 1];
    // dist가 x의 배수면 하나가 더 포함된다
    int need = dist / x;
    cnt += (dist % x == 0) ? need - 1 : need;
  }
  /**
   * 휴게소의 개수가 m보다 커지면 모두 설치할 수 없으므로 간격을 더 벌려야 함
   * m보다 같거나 작다면(모두 설치해야해서 작은 경우는 없긴 함) 간격을 더 줄일
   * 수 있고 이것을 찾는게 목표
   */
  return cnt > m;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> l;
  rest.resize(n);
  for (auto& pt : rest) cin >> pt;
  rest.push_back(0);
  rest.push_back(l);
  sort(rest.begin(), rest.end());
  int st = 0, en = l;
  while (st < en) {
    int mid = (st + en) / 2;
    if (possible(mid))
      st = mid + 1;
    else
      en = mid;
  }
  cout << st;
  return 0;
}