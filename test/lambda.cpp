#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int sum = 0;
  [&sum]() { sum += 5; }();
  cout << sum << '\n';
  [sum]() mutable { sum += 5; }();
  cout << sum << '\n';
  return 0;
}