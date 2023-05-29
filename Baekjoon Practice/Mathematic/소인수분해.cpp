#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 2; i * i <= n; ++i) {

    while (n % i == 0) {
      cout << i << '\n';
      n /= i;
    }
  }
  // i*i <= n 이거 때문에 필요 n=3일때만 예외로 안된다...

  if (n > 1) {
    cout << n << '\n';
  }

  return 0;
}