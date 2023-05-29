#include <iostream>

using namespace std;

int main() {

  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      cout << " ";
    }

    for (int k = 0; k < i * 2 + 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << ' ';
    }
    for (int j = i; j < n * 2 - 1 - i; j++) {
      cout << '*';
    }
    cout << "\n";
  }
  return 0;
}