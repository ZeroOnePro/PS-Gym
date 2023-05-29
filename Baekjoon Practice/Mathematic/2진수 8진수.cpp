#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string binary;
  cin >> binary;
  int n = binary.size();
  if (n % 3 == 1) {
    cout << binary[0];
  } else if (n % 3 == 2) {
    cout << (binary[0] - '0') * 2 + (binary[1] - '0');
  }
  for (int i = n % 3; i < n; i += 3) {
    cout << (binary[i] - '0') * 4 + (binary[i + 1] - '0') * 2 +
                (binary[i + 2] - '0');
  }
  cout << '\n';
  return 0;
}