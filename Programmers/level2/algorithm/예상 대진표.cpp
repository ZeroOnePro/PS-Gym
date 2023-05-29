#include <bits/stdc++.h>

using namespace std;

/**
 * (홀수, 짝수)가 대결을 한다
 * (1, 2) => 1
 * (3, 4) => 2
 * (5, 6) => 3
 * (7, 8) => 4
 * .. 이런 규칙이 있네
 * 홀수의 짝은 +1하면 되고 짝수의 짝은 -1하면 됨
 * 홀수는 짝과 더해서 2로 나눈 몫 + 1, 짝수는 짝과 더해서 2로 나눈 몫이 다음
 * 라운드의 번호가 된다 A와 B가 만나는지는 A가 홀수일 때는 B가 A+1인지, 짝수일
 * 땐 A-1인지 보면 됨
 */

int nxt_num(int n) { return n / 2 + (n & 1); }

bool check(int a, int b) {
  if (a & 1)
    return b == a + 1;
  else
    return b == a - 1;
}

int solution(int n, int a, int b) {
  int answer = 1;
  while (!check(a, b)) {
    a = nxt_num(a);
    b = nxt_num(b);
    answer += 1;
  }
  return answer;
}