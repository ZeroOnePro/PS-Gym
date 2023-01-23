#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  stack<int> s;
  int n;
  cin >> n;
  while (n--) {
    string op;
    cin >> op;
    if (op == "pop") {
      if (s.empty())
        cout << -1 << '\n';
      else {
        cout << s.top() << '\n';
        s.pop();
      }
    } else if (op == "size") {
      cout << s.size() << '\n';
    } else if (op == "top") {
      if (s.empty())
        cout << -1 << '\n';
      else
        cout << s.top() << '\n';
    } else if (op == "empty") {
      cout << (int)s.empty() << '\n';
    } else {
      int element;
      cin >> element;
      s.push(element);
    }
  }
  return 0;
}