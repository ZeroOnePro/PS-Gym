#include <cstring>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string init;
  cin >> init;

  stack<char> left, right;
  // 명령어가 들어오기 전 커서는 문장의 오른쪽 끝에 위치
  for (char ch : init) {
    left.push(ch);
  }

  int m;
  cin >> m;

  while (m--) {
    char inst;
    cin >> inst;
    if (inst == 'L') {
      // 커서가 문장의 맨 앞이면 무시됨
      // 즉 왼쪽 스택이 빈 것.
      if (!left.empty()) {
        // 왼쪽으로 옮기기 때문에 왼쪽 스택의 것이 푸쉬
        // 오른쪽 스택으로 팝
        right.push(left.top());
        left.pop();
      }
    } else if (inst == 'D') {
      // 커서가 문장의 맨 뒤면 무시됨
      // 오른쪽 스택이 빈 것
      if (!right.empty()) {
        // 오른쪽 스택의 것이 팝 되어
        // 왼쪽 스택으로 팝
        left.push(right.top());
        right.pop();
      }
    } else if (inst == 'B') {
      // 커서 왼쪽의 문자를 삭제
      // 왼쪽 스택에서 POP됨
      // 커서가 문장의 맨 앞이면 무시됨
      if (!left.empty()) {
        left.pop();
      }
    } else if (inst == 'P') {
      // 문자를 커서 왼쪽에 추가
      char ch;
      cin >> ch;
      left.push(ch);
    }
  }

  // 왼쪽과 오른쪽 스택이 합쳐지고 하나의 문자열이 되야하고
  // 왼쪽의 첫번째 문자부터 나와야 하므로
  // 생각해보면 왼쪽의 마지막 부터 오른쪽에 팝되고
  // 오른쪽의 top부터 꺼내면 문자열이 왼 -> 오 순서대로 나오게 된다.

  while (!left.empty()) {
    right.push(left.top());
    left.pop();
  }

  while (!right.empty()) {
    cout << right.top();
    right.pop();
  }

  return 0;
}