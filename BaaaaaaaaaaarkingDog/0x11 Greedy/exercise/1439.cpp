#include <bits/stdc++.h>

using namespace std;

int cnt[2];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int len = s.length();
  int cur = 0;
  bool st = false;
  while (cur < len) {
    while (s[cur] == '0') {
      cur += 1;
      st = true;
    }
    if (st) cnt[0] += 1;
    st = false;
    while (s[cur] == '1') {
      cur += 1;
      st = true;
    }
    if (st) cnt[1] += 1;
    st = false;
  }
  cout << min(cnt[0], cnt[1]);
  return 0;
}