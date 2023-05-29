#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++)
      cout << ' ';
    for (int g = 0; g <= n - i; g++)
      cout << '*';
    cout << '\n';
  }
  return 0;
}