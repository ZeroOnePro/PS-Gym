#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  // a가 b의 약수
  do {
    if (a < b && b % a == 0) {
      cout << "factor" << '\n';
    } else if (a > b && a % b == 0) {
      cout << "multiple" << '\n';
    } else {
      cout << "neither" << '\n';
    }
    cin >> a >> b;
  } while (a != 0 && b != 0);
  return 0;
}