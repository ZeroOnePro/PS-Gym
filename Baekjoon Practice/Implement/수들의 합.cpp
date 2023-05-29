#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long s;
  cin >> s;
  long long cursor = 1;
  while (1) {
    // 1 + 2 + 3 + ... + n = n(n-1)/2
    long long prac_sum1 = cursor * (cursor + 1) / 2;
    long long prac_sum2 = (cursor + 1) * (cursor + 2) / 2;
    if (prac_sum1 <= s && s < prac_sum2) {
      break;
    }
    cursor += 1;
  }
  cout << cursor;
  return 0;
}
