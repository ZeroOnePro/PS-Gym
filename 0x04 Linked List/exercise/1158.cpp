#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  list<int> seq;
  vector<int> jose;
  for (int i = 1; i <= n; ++i) seq.push_back(i);
  auto cur = seq.begin();
  while (jose.size() != n) {
    int i = k - 1;
    while (i--) {
      cur = next(cur) == seq.end() ? seq.begin() : next(cur);
    }
    jose.push_back(*cur);
    // 끝 원소 삭제하면 erase는 end()를 반환
    cur = seq.erase(cur);
    if (cur == seq.end()) cur = seq.begin();
  }
  cout << '<';
  for (auto it = jose.begin(); it != jose.end(); it++) {
    cout << *it;
    if (it != jose.end() - 1) cout << ", ";
  }
  cout << '>';
  return 0;
}