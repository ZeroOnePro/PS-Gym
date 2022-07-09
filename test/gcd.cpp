#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  while (true) {
    int r = b > a ? b % a : a % b;
    b = a;
    a = r;
    if (r == 0) break;
  }
  return b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b);
  return 0;
}