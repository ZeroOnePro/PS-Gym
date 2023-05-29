#include <bits/stdc++.h>

using namespace std;

/**
 * arrayA가 모두 나누어 떨어지는 최대의 수 = 최대 공약수이고
필자 분의 말씀은 최대 공약수의 약수 목록 중에서 arrayB가
나누어지지 않는 수를 찾아야 하는 것 이 아니냐? 라는 질문을 하셨는데

만약 arrayA의 최대 공약수가 72 라면
최대 공약수의 약수는
{1, 2, 3, 4, 6, 8, 9, 12, 18, 24, 36, 72} 들 이 있습니다.

하지만 arrayB에 72로 나누어 떨어지는 수(72의 배수) 가 있다면
당연히 72의 약수로도 나누어 떨어지게 됩니다.

따라서 최대 공약수만으로 계산하셔도 무방합니다.

만약 약수 크기에 상한이 있다면 (예 : 72의 약수 중 30이하)
의 경우엔 18(2, 3, 3)과 24(2, 2, 2, 3) 중에 나누어 떨어지지 않는 것 으로
골라야하는 문제가 됐을 겁니다.
 */

int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int clac_gcd(int g, vector<int>& num) {
  for (int i = 2; i < num.size(); ++i) g = gcd(g, num[i]);
  return g;
}

int clac_max_divisor(int g, vector<int>& num) {
  for (int i = 0; i < num.size(); ++i)
    if (num[i] % g == 0) return 1;
  return g;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
  int answer = 0;
  if (arrayA.size() == 1) {
    if (arrayA[0] != arrayB[0])
      return max(arrayA[0], arrayB[0]);
    else
      return 0;
  }
  int g1 = clac_gcd(gcd(arrayA[0], arrayA[1]), arrayA);
  int g2 = clac_gcd(gcd(arrayB[0], arrayB[1]), arrayB);
  int d1 = clac_max_divisor(g1, arrayB);
  int d2 = clac_max_divisor(g2, arrayA);
  if (d1 == 1 && d2 == 1)
    answer = 0;
  else
    answer = max(d1, d2);
  return answer;
}
