#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string a, b;
  char op;
  cin >> a >> op >> b;
  switch (op) {
  case '+':
    if (a.length() < b.length()) {
      for (int i = 0; i < b.length(); ++i) {
        if (i == 0 || i == b.length() - a.length())
          cout << 1;
        else
          cout << 0;
      }
    } else if (a.length() == b.length()) {
      for (int i = 0; i < a.length(); ++i) {
        if (i == 0)
          cout << 2;
        else
          cout << 0;
      }
    } else {
      for (int i = 0; i < a.length(); ++i) {
        if (i == 0 || i == a.length() - b.length())
          cout << 1;
        else
          cout << 0;
      }
    }
    break;
  case '*':
    for (int i = 0; i <= (a.length() - 1) + (b.length() - 1); i++) {
      if (i == 0)
        cout << 1;
      else
        cout << 0;
    }
    break;
  }
  cout << '\n';
  return 0;
}