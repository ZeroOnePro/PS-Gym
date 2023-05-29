#include <iostream>

using namespace std;

int five_square = 5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int cnt = 0;
  while (five_square <= n) {
    cnt += (n / five_square);
    five_square *= 5;
  }

  cout << cnt << '\n';

  return 0;
}