#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    string ps;
    bool is_valid = true;
    stack<char> s;
    cin >> ps;
    for (char ch : ps) {
      if (ch == '(')
        s.push(ch);
      else {
        if (!s.empty()) {
          if (s.top() == ')') {
            is_valid = false;
            break;
          } else
            s.pop();
        } else {
          is_valid = false;
          break;
        }
      }
    }
    if (!s.empty()) is_valid = false;
    cout << (is_valid ? "YES" : "NO") << '\n';
  }
  return 0;
}