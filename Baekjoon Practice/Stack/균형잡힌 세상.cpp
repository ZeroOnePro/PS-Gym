#include <iostream>
#include <stack>
#include <string>

using namespace std;

string valid(string str) {

  stack<char> s;

  for (char ch : str) {

    if (ch == '(' || ch == '[') {
      s.push(ch);

    } else if (ch == ']') {
      if (!s.empty() && s.top() == '[')
        s.pop();
      else
        return "no";
    } else if (ch == ')') {
      if (!s.empty() && s.top() == '(')
        s.pop();
      else
        return "no";
    } else {
      continue;
    }
  }

  if (s.size() == 0) {
    return "yes";
  } else {
    return "no";
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input;

  while (1) {
    // string class는 공백기준으로 문자열이 구분되어
    // 입력으로 한 줄 자체를 얻을 때는 getline을 사용!
    getline(cin, input);
    if (input == ".")
      break;
    cout << valid(input) << '\n';
  }

  return 0;
}