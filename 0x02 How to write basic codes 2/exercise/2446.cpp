#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; ++i) {
    if (n >= i) {
      for (int k = 1; k < i; ++k) cout << ' ';
    } else {
      for (int k = i; k < 2 * n - 1; ++k) cout << ' ';
    }
    for (int j = 2 * (abs(n - i)) + 1; j > 0; --j) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}