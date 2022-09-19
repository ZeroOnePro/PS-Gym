#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int k = 1; k < i; ++k) {
      cout << ' ';
    }
    for (int j = 2 * n - (2 * i - 1); j > 0; --j) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}