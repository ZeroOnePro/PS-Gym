#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int total;
  int accum_price = 0;
  int input;
  std::cin >> total;
  for (int i = 0; i < 9; ++i) {
    std::cin >> input;
    accum_price += input;
  }
  std::cout << total - accum_price << '\n';
  return 0;
}