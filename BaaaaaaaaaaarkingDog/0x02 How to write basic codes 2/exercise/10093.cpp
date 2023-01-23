#include <bits/stdc++.h>

using namespace std;

// a가 b보다 크거나 같은 경우를 생각하지 못했음
// 10^15면 int의 최대범위 넘어가는데 이 사실을 간과했음

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << '\n';
    return 0;
  }
  if (a > b) swap(a, b);
  cout << b - a - 1 << '\n';
  for (long long i = a + 1; i < b; ++i) {
    cout << i;
    if (i != b - 1) cout << ' ';
  }
  return 0;
}