#include <bits/stdc++.h>

using namespace std;

int convert(char ch) { return ch == '(' || ch == ')' ? 2 : 3; }

bool match(char l, char r) {
  return (l == '(' && r == ')') || (l == '[' && r == ']');
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  stack<char> m;
  int sum = 0, mul = 1;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '(' || s[i] == '[') {
      mul *= convert(s[i]);
      m.push(s[i]);
    } else {
      if (m.empty() || !match(m.top(), s[i])) {
        cout << 0;
        return 0;
      }
      if (match(s[i - 1], s[i])) sum += mul;
      mul /= convert(s[i]);
      m.pop();
    }
  }
  cout << (!m.empty() ? 0 : sum);
  return 0;
}