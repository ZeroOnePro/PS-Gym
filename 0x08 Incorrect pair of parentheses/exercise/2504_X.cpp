#include <bits/stdc++.h>

using namespace std;

int acc(char ch) { return ch == ')' || ch == '(' ? 2 : 3; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  stack<char> s;
  cin >> str;
  int index = 0, sum = 0, multiplier = 1;
  bool is_correct = true;
  for (char ch : str) {
    if (ch == '(' || ch == '[') {
      multiplier *= acc(ch);
      s.push(ch);
    } else {
      if (s.empty() || (ch == ']' && s.top() != '[') ||
          (ch == ')' && s.top() != '(')) {
        is_correct = false;
        break;
      } else {
        if (str[index - 1] == '[' || str[index - 1] == '(') sum += multiplier;
        multiplier /= acc(ch);
        s.pop();
      }
    }
    index += 1;
  }
  if (!s.empty()) is_correct = false;
  cout << (is_correct ? sum : 0) << '\n';
  return 0;
}