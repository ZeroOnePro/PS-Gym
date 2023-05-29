#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int op_cnt = 0;
  while (n >= k) {
    while (n % k != 0) {
      n -= 1;
      op_cnt += 1;
    }
    n /= k;
    op_cnt += 1;
  }
  while (n > 1) {
    n -= 1;
    op_cnt += 1;
  }
  cout << op_cnt << '\n';
  return 0;
}