#include <iostream>

using namespace std;

// O(logN)의 방법으로
// 2 ~ 루트 n까지만 검사
bool isPrime(int n) {
  if (n < 2) {
    // 1은 소수아녀~
    return false;
  }

  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    if (isPrime(input)) {
      cnt += 1;
    }
  }

  cout << cnt << '\n';

  return 0;
}