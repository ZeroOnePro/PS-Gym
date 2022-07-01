#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < 2 * n; ++i) {
    if (i < n)
      cin >> a[i];
    else
      cin >> b[i - n];
  }
  sort(a, a + n);
  sort(b, b + n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i] * b[n - i - 1];
  }
  cout << s;
  return 0;
}