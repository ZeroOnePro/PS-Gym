#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int op_cnt = 0;
  // 배수 이용하기
  int target;
  while (true) {
    target = (n / k) * k;   // target은 k의 배수
    op_cnt += (n - target); // 배수로 맞추기위해 필요한 -1의 수를 op_cnt에 누적
    n = target;             // 배수가 됨
    if (n < k)
      break;
    op_cnt += 1; // 나눈 회수
    n /= k;      // 나누고 다시 위부터 시작
  }
  op_cnt += (n - 1); // -1을 하여 1로 만들기 위해 연산이 몇번이 필요한가? n-1번
  return 0;
}