#include <bits/stdc++.h>

using namespace std;

long long power_of_n(long long base, long long power, long long r) {
  if (power == 1) return base % r;
  long long acc = power_of_n(base, power / 2, r);
  acc = acc * acc % r;
  // 짝수 제곱 처리
  if (power % 2 == 0) return acc;
  // 홀수 제곱 처리
  return (acc * (base % r)) % r;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a, b, c;
  cin >> a >> b >> c;
  cout << power_of_n(a, b, c) << '\n';
  return 0;
}

/* 이 문제에 필요한 수학적 지식

** 1. a^n * a^n = a^2n
** 2. ab mod c = ((a mod c) * (b mod c)) mod c

*/

/* 이 문제의 특이점

**  지수가 20억을 넘어서 기존의 거듭제곱 계산법 O(n)으로 해결할 수 없다.
** 따라서 수학적 지식과 귀납적 사고를 통해 문제를 해결해야함
** n번 연속적으로 곱하던 것을 지수법칙을 이용하여 n의 결과에 n/2이 이용되므로
log 시간복잡도로 줄일 수 있다.

** a^2b mod c = ((a^b mod c) * (a^b mod c)) mod c
** ...
** a^2 mod c = ((a mod c) * (a mod c)) mod c => base condition

** a^2b+1 mod c = (a^2b * a) mod c = ((a^2b mod c) * (a mod c)) mod c

*/