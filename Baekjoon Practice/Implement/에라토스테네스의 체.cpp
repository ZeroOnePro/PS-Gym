#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> check(n + 1, false);
  int cnt = 0;
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n / i; ++j) {
      if (!check[i * j]) {
        check[i * j] = true;
        cnt += 1;
        if (cnt == k) {
          ans = i * j;
          break;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}