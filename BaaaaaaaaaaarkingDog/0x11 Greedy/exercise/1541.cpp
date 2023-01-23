#include <bits/stdc++.h>

using namespace std;

int oper(bool is_minus, int ans, stack<int>& s) {
  int num = 0, mul = 1;
  while (!s.empty()) {
    num += s.top() * mul;
    mul *= 10;
    s.pop();
  }
  if (is_minus)
    ans -= num;
  else
    ans += num;
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  bool is_minus = false;
  string exp;
  stack<int> s;
  cin >> exp;
  int ans = 0;
  for (char c : exp) {
    if (isdigit(c))
      s.push(c - '0');
    else {
      ans = oper(is_minus, ans, s);
      if (c == '-') is_minus = true;
    }
  }
  ans = oper(is_minus, ans, s);
  cout << ans;
  return 0;
}