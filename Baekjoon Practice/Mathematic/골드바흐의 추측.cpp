
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int primes = 0;
bool check[MAX + 1];
int eratosthenes[MAX];

void Goldbach() {

  // 0,1 예외 처리
  check[0] = check[1] = true;
  // i*i ~ n까지는 그 전 단계에서 걸러짐
  for (int i = 2; i <= MAX; ++i) {
    if (!check[i]) {
      // 소수 갯수 세기
      eratosthenes[primes++] = i;
      // i*i는 오버플로우 우려때문에 2*i로 하는게 안전
      for (int j = 2 * i; j <= MAX; j += i) {
        check[j] = true;
      }
    }
  }

  while (1) {
    int n;
    cin >> n;
    if (!n)
      break;
    //발견된 소수의 갯수만큼 반복
    for (int i = 1; i < primes; i++) {
      if (!check[n - eratosthenes[i]]) {
        // 입력된 수 - 발견된 소수(첫번째 부터) = 이것도 소수이면
        // 나는 2중루프 돌려서 pair로 찾을라 그랬는데 => 시간초과
        // 인덱싱 차이로 점점 좁혀가면서 두 소수의 순서쌍을 생성 !!
        // 순서쌍의 합으로 어떤 특정 조건을 만족하는 수 구할때 써먹으면 좋은
        // 기술
        cout << n << " = " << eratosthenes[i] << " + " << n - eratosthenes[i]
             << '\n';
        break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Goldbach();
  return 0;
}