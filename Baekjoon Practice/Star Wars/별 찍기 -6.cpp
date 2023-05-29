#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int tmp = 2 * n - 1;
  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < i; ++j) {
      cout << ' ';
    }

    for (int k = 0; k < tmp; ++k) {
      cout << '*';
    }
    tmp -= 2;
    cout << '\n';
  }
  return 0;
}