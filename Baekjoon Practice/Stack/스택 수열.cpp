#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  string solution;
  stack<int> s;
  int m = 0; // 스택에 들어간 마지막 수

  while (n--) {
    int x;
    cin >> x;
    if (x > m) {
      while (x > m) {
        s.push(m += 1);  // 스택을 m+1 ~ x까지 채운다.
        solution += '+'; // push 니깐 '+'
      }
      s.pop();         // x를 pop
      solution += '-'; // pop 이니깐 '-'
    } else {           // x <= m
      // 이 경우는 어차피 x <= m 이라면, x == m이어야 한다.
      // m보다 작은 것을 pop하려 하면
      // 스택 수열의 조건에 위배된다.
      bool found = false;
      if (!s.empty()) {    // stack이 비지않았으면,
        int top = s.top(); // top을 꺼내고
        s.pop();           // pop 시킨다.
        solution += '-';   // pop 이니깐 '-'
        if (x == top) {    // 꺼낸것이 x와 같다면
          found = true;    // 찾은 것임
        }
      }
      if (!found) {
        cout << "NO" << '\n';
        return 0;
      }
    }
  }

  for (char ch : solution) {
    cout << ch << '\n';
  }

  return 0;
}