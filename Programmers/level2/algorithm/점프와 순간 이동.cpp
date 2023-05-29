#include <bits/stdc++.h>

using namespace std;

// 건전지 사용횟수를 최소로 하려면 최대한 많은 순간이동을 해야함
// 순간이동을 사용하지 못했던 경우는 홀수일 때 뿐임(2를 곱했는데 홀수가 나오는
// 경우는 없으므로, 무조건 점프만 가능) 2로 나눠가며 0이될 때까지 홀수의 등장
// 횟수가(이진수로 만들면서 1이 몇 번 나오는지) 건전지 사용횟수라 할 수 있다
// 1칸만 이동해서 짝수를 만들어주는게 건전지를 최소로 사용할 수 있음

int solution(int n) {
  int ans = 0;
  for (int i = n; i >= 1; i >>= 1) ans += i & 1;
  // 참고 return __builtin_popcount(n); gcc builtin 함수를 이용하면 비트에서 1의
  // 개수를 셀 수 있음
  return ans;
}