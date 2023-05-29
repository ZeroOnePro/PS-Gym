#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];
int eratosthenes[MAX];
int cnt;
int primes;

int Goldbach(const int n) {
  cnt = 0;
  primes = 0;
  // 0,1 예외 처리
  check[0] = check[1] = true;
  // i*i ~ n까지는 그 전 단계에서 걸러짐
  for (int i = 2; i <= n; ++i) {
    if (!check[i]) {
      // 소수 갯수 세기
      eratosthenes[primes++] = i;
      // i*i는 오버플로우 우려때문에 2*i로 하는게 안전
      for (int j = 2 * i; j <= n; j += i) {
        check[j] = true;
      }
    }
  }
  int loop = 0; // 쌍의 갯수 => 소수의 갯수의 절반
  for (int i = 1; i < primes; ++i) {
    // 중복 제거 기술.. 교차 했을때부터 안 세주면 된다.
    if (n - eratosthenes[i] >= eratosthenes[i]) {
      // n-eratosthenes가 더 큰 상태로 루프가 시작하니깐..
      if (!check[n - eratosthenes[i]]) {
        cnt += 1;
      }
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    cout << Goldbach(n) << '\n';
  }
  return 0;
}