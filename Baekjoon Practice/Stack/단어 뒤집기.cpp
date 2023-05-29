#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  cin.ignore(); // tc 다음의 개행문자 무시
  string str;
  stack<char> s; // 스택 사용법
  while (tc--) {
    getline(cin, str);
    str += '\n';
    for (char ch : str) { // string 문자별로 훑기
      if (ch == '\n' || ch == ' ') {
        while (!s.empty()) {
          cout << s.top();
          s.pop();
        }
        cout << ch;
      } else {
        s.push(ch);
      }
    }
  }
  return 0;
}
