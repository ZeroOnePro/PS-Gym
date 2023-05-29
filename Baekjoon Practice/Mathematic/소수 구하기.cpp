#include <iostream>
#include <vector>

using namespace std;
// 에라토스테네스의 체
// check배열만 만들면 됨..
// check배열의 인덱스가 후보군이고 check배열의 값은 소수인지 아닌지를 나타냄
void Primes(int m, int n) {
  vector<bool> check(n + 1, false);
  // 0,1 예외 처리
  check[0] = check[1] = true;
  // i*i ~ n까지는 그 전 단계에서 걸러짐
  for (int i = 2; i <= n; ++i) {
    if (!check[i]) {
      // i*i는 오버플로우 우려때문에 2*i로 하는게 안전
      for (int j = 2 * i; j <= n; j += i) {
        check[j] = true;
      }
    }
  }

  // m ~ n 사이의 모든 소수 출력
  for (int i = m; i <= n; ++i) {
    if (!check[i]) {
      cout << i << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int m, n;
  cin >> m >> n;
  Primes(m, n);
  return 0;
}