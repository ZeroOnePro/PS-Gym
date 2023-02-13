#include <bits/stdc++.h>

using namespace std;

// 뒤에서부터 다른거 먼저 옮기는게 이득이네 => 순서때문에

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a, b;
  cin >> a >> b;
  int cnt = 0, cur = 0, n = a.length();
  cout << '\n';
  while (a != b) {
    while (cur < n && a[cur] != b[cur]) cur += 1;
    cur -= 1;
    b = b[cur] + b;
    b.erase(b.begin() + cur + 1);
    cout << b << '\n';
    cur = 0;
    cnt += 1;
  }
  cout << cnt;
  return 0;
}