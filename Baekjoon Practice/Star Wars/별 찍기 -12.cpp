#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n - i; ++j) {
      cout << ' ';
    }
    for (int k = 1; k <= i; ++k) {
      cout << '*';
    }
    cout << '\n';
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      cout << ' ';
    }
    for (int k = 1; k <= n + 1 - i; ++k) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}