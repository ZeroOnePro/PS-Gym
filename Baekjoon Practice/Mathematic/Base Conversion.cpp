#include <iostream>

using namespace std;

void conversion(int n, int base) {
  if (n == 0)
    return;
  conversion(n / base, base);
  cout << n % base << ' ';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  int m;
  cin >> m;
  int ans = 0;
  while (m--) {
    int n;
    cin >> n;
    // a가 누적되고 제일 늦게 들어오는 n은 a가 곱해지지않으니
    // xn * a^n + xn-1 * a^n-1 + ... 의 식이 된다.
    ans = ans * a + n;
  }
  conversion(ans, b);
  return 0;
}