#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
    stack<char> seq;
    bool isCorrect = true;
    string sentence;
    getline(cin, sentence);
    if (sentence == ".") break;
    for (char ch : sentence) {
      if (ch == '(' || ch == '[')
        seq.push(ch);
      else if (ch == ')' || ch == ']') {
        if (seq.empty()) {
          isCorrect = false;
          break;
        } else {
          if ((ch == ')' && seq.top() == '(') ||
              (ch == ']' && seq.top() == '[')) {
            seq.pop();
          } else {
            isCorrect = false;
            break;
          }
        }
      }
    }
    if (!seq.empty()) {
      isCorrect = false;
    }
    cout << (isCorrect ? "yes" : "no") << '\n';
  }
  return 0;
}