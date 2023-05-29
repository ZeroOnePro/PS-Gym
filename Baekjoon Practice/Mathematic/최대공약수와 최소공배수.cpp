#include <iostream>

using namespace std;

int GCD(int a, int b) {
  // 최대공약수
  // 유클리드 호제법
  // GCD(a,b) = GCD(b,a%b) a가 크든 b가 크든 상관 없음
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b;

  cin >> a >> b;
  // 최소공배수 = a*b / 최대공약수
  cout << GCD(a, b) << '\n' << (a * b) / GCD(a, b) << '\n';
  return 0;
}