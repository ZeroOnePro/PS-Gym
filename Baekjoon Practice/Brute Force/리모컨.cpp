#include <iostream>
#include <vector>

using namespace std;

vector<bool> broken(11);

int absolute(int n) { return n < 0 ? -n : n; }

int check(int c) {
  if (c == 0) {
    return broken[0] ? 0 : 1;
  }
  int len = 0;
  // 한 자리씩 검사
  while (c > 0) {
    if (broken[c % 10])
      return 0;
    len += 1;
    c /= 10;
  }
  return len;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, b;
  cin >> n >> b;
  for (int i = 0; i < b; ++i) {
    int button;
    cin >> button;
    broken[button] = true;
  }

  int ans = 100 - n;

  ans = absolute(ans);

  for (int i = 0; i <= 1000000; ++i) {
    int len = check(i);
    if (len > 0) {
      int pm = 0;
      pm = i - n;
      pm = absolute(pm);
      if (ans > len + pm) {
        ans = len + pm;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}