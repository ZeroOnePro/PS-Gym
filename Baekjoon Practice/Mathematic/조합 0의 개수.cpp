#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

ll cnt = 0;

ll count_machine(ll fac, ll n) {
  cnt = 0;
  ll square = n;
  while (square <= fac) {
    cnt += (fac / square);
    square *= n;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // 조합공식
  //	  nCm
  //     n!
  //------------
  // (n-m)! * m!
  // 여기서는 나눠지기 때문에 2와 5의 쌍을 모두 찾아줘야함..
  // 왜나면 2의 갯수가 더 많은지 5의 갯수가 더 많은지 예측이 어려움..
  ll n, m;
  cin >> n >> m;
  // 1) n!의 2와 5의 갯수 세고
  // 2) (n-m)!의 2와 5의 갯수 세고
  // 3) m!의 2와 5의 갯수 세고
  // 1) - { 2) + 3) }
  // 둘 중의 더 적게 나온것을 택해야 쌍이 맞춰지겠지?
  ll five = count_machine(n, 5) - count_machine(n - m, 5) - count_machine(m, 5);

  ll two = count_machine(n, 2) - count_machine(n - m, 2) - count_machine(m, 2);

  ll result = min(two, five);

  cout << result << '\n';

  return 0;
}