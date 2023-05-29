#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int total1 = 0, total2 = 0;
  int temp;
  for (int i = 0; i < 4; ++i) {
    cin >> temp;
    total1 += temp;
  }
  for (int i = 0; i < 4; ++i) {
    cin >> temp;
    total2 += temp;
  }
  total1 > total2 ? cout << total1 << '\n' : cout << total2 << '\n';
  return 0;
}