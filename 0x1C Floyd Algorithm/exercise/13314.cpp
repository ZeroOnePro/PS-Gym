#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 100;
  cout << n << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j)
        cout << 0 << ' ';
      else if (i == n || j == n)
        cout << 0 << ' ';
      else
        cout << 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}