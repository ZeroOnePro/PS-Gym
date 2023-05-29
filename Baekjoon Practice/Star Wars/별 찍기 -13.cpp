#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= j; ++i) {
      cout << '*';
    }
    cout << '\n';
  }
  for (int j = 1; j < n; ++j) {
    for (int i = n - j; i >= 1; --i) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}