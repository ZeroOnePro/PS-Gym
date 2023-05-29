#include <iostream>
#include <stack>

using namespace std;
// + - * / ( ) 鉴辑
int precedence(char ch) {
  if (ch == '(')
    return 0;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return 2;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string infix;
  string postfix;

  cin >> infix;
  stack<char> s;

  for (char ch : infix) {
    // ( ) 贸府
    // + - * / 快急鉴困 贸府
    if (ch >= 'A' && ch <= 'Z') {
      postfix += ch;
    } else if (ch == '(') {
      s.push(ch);
    } else if (ch == ')') {
      while (!s.empty()) {
        char op = s.top();
        s.pop();
        if (op == '(')
          break;
        postfix += op;
      }
    } else {
      while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
        postfix += s.top();
        s.pop();
      }
      s.push(ch);
    }
  }

  while (!s.empty()) {
    char op = s.top();
    s.pop();
    postfix += op;
  }

  cout << postfix << '\n';

  return 0;
}