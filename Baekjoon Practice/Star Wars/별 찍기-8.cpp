#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cout << '*';
    }
    for (int k = 1; k <= 2 * (n + 1 - i) - 2; ++k) {
      cout << ' ';
    }
    for (int g = 1; g <= i; ++g) {
      cout << '*';
    }
    cout << '\n';
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= n - i; ++j) {
      cout << '*';
    }
    for (int k = 1; k <= 2 * (i - 1) + 2; ++k) {
      cout << ' ';
    }
    for (int g = 1; g <= n - i; g++) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}