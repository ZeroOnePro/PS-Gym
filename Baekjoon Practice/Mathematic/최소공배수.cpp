#include <iostream>

using namespace std;

int GCD(int a, int b) {

  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int a, b;
    cin >> a >> b;
    cout << (a * b) / GCD(a, b) << '\n';
  }

  return 0;
}