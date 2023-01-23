#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int year;
  cin >> year;
  bool isLeapYear = true;
  if (year % 4 != 0) isLeapYear = false;
  if (!(year % 100 != 0 || year % 400 == 0)) isLeapYear = false;
  cout << isLeapYear ? '1' : '0' << '\n';
  return 0;
}