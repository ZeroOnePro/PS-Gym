#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  deque<int> dq;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) dq.push_back(i);
  int cnt = 0;
  while (m--) {
    int target;
    cin >> target;
    while (target != dq.front()) {
      deque<int>::iterator cursor = find(dq.begin(), dq.end(), target);
      if (cursor <= (dq.size() / 2) + dq.begin()) {
        dq.push_back(dq.front());
        dq.pop_front();
      } else {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      cnt += 1;
    }
    dq.pop_front();
  }
  cout << cnt << '\n';
  return 0;
}