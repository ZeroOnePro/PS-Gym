#include <iostream>
#include <stack>
#include <string>

using namespace std;

void word_printer(stack<char> &s) {
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input;
  stack<char> s;
  getline(cin, input);
  bool tag = false;

  for (char ch : input) {
    if (ch == '<') {
      // open tag는 그 전까지의 문자를 출력하고
      word_printer(s);
      // 태그 시작을 알림
      tag = true;
      // < 출력
      cout << ch;
    } else if (ch == '>') {
      // 태그 끝을 알림
      tag = false;
      // > 출력
      cout << ch;
    } else if (tag) {
      // 태그 내부 문자들
      cout << ch;
    } else {
      // 태그 외부 문자들
      if (ch == ' ') {
        word_printer(s);
        cout << ch;
      } else {
        s.push(ch);
      }
    }
  }
  // 문자열의 끝이 공백이 아니라고 했으니
  // 스택내부의 문자들을 한번 더 출력해줄 필요가있다
  // 반복문 내부에서는 공백을 만났을 시만 출력이 되기때문
  word_printer(s);
  cout << '\n';
  return 0;
}