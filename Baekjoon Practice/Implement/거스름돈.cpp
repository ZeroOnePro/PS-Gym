#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m = 0;
  int count = 0;
  cin >> m;
  m = 1000 - m;
  if (m >= 500) {
    count += m / 500;
    m %= 500;
  }
  if (m >= 100) {
    count += m / 100;
    m %= 100;
  }
  if (m >= 50) {
    count += m / 50;
    m %= 50;
  }
  if (m >= 10) {
    count += m / 10;
    m %= 10;
  }
  if (m >= 5) {
    count += m / 5;
    m %= 5;
  }
  if (m >= 1) {
    count += m / 1;
  }
  cout << count << '\n';
  return 0;
}