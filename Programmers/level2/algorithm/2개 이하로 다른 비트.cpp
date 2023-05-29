#include <bits/stdc++.h>

using namespace std;

// 서로 다른 비트 개수 = xor 결과의 1의 개수
/*
    홀수는 끝 비트가 1이므로 비트로 표현했을 때 제일 오른쪽의 0을 1로 뒤집고, 그
   0의 다음 1을 0으로 바꿔준다
    -  제일 오른쪽 0인 이유는 가장 작은 수를 찾기 위함, 2개를 다르게 만들어줘야
   하므로 그 다음 1을 0으로 뒤집는다 짝수는 끝 비트가 0이므로 +1 해주면 끝(x와
   x+1을 비트로 나타내서 확인해보면 쉽게 확인 가능)
*/

typedef long long ll;

vector<ll> solution(vector<ll> numbers) {
  vector<ll> answer;
  for (ll number : numbers) {
    if (number & 1) {
      int digit = 0;
      ll tmp = number;
      while (tmp & 1) {
        tmp >>= 1;
        digit += 1;
      }
      /*
       * 1 << x로 bitwise 하면 오버플로가 날 수도 있다
       * long long을 쉬프트 할 때는 왼쪽 피연산자도 long long으로 해주자
       */
      number |= 1LL << digit;
      number ^= 1LL << (digit - 1);
      answer.push_back(number);
    } else
      answer.push_back(number + 1);
  }
  return answer;
}