#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int sum = 0;
  for (int start = 1, len = 1; start <= n; start *= 10, len += 1) {
    int end = 10 * start - 1;
    if (end > n) {
      end = n;
    }
    sum += len * (end - start + 1);
  }
  cout << sum << '\n';
  return 0;
}