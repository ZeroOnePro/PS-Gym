#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b, c, d, p;
  int price_x = 0, price_y = 0;
  cin >> a >> b >> c >> d >> p;
  price_x += p * a;
  p > c ? price_y = b + (p - c) *d : price_y = b;
  price_x < price_y ? cout << price_x << '\n' : cout << price_y << '\n';
  return 0;
}