#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, l;
  cin >> n >> l;
  deque<pair<int, int>> dq;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    // 오름 차순 유지시키기 위해 덱에서 인풋보다 작은거 다 빼기, 갖고 있을
    // 필요 없음
    while (!dq.empty() && dq.back().second >= a) dq.pop_back();
    dq.push_back({i, a});
    // 구간 내 숫자 아닌 것들 제거
    while (dq.front().first <= i - l) dq.pop_front();
    cout << dq.front().second << ' ';
  }
  return 0;
}