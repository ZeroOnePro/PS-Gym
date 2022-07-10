#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
  int x = 1;
  for (int i = 1; i <= n; ++i) x *= i;
  return x;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  cout << factorial(n) / (factorial(k) * factorial(n - k));
  return 0;
}