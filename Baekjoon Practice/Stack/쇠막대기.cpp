#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input;

  cin >> input;

  stack<char> s;

  int cnt = 0;
  // 문자열 인덱싱
  int i = 0;
  for (char ch : input) {
    if (ch == '(') {
      s.push(ch);
    } else {
      // 막대기, 레이저 구분
      // 레이저
      if (input.at(i - 1) == '(') {
        s.pop();
        // 레이저
        cnt += s.size();
      }
      // 막대기
      else {
        s.pop();
        cnt += 1;
      }
    }
    i++;
  }

  cout << cnt << '\n';

  return 0;
}