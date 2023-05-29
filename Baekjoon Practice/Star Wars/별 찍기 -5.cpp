#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = n - i; j > 0; j--) {
      cout << ' ';
    }
    for (int k = 0; k < 2 * i - ; k++) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}