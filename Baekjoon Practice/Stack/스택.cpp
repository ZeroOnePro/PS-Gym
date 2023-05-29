#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
  int size = 0;
  int stack[100000];

public:
  void push(int element) {
    stack[size] = element;
    size += 1;
  }

  void pop() {
    if (size == 0) {
      cout << -1 << '\n';
      return;
    }
    cout << stack[size - 1] << '\n';
    stack[size - 1] = 0;
    size -= 1;
  }

  void empty() {
    if (size == 0) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }

  void top() {
    if (size == 0) {
      cout << -1 << '\n';
    } else {
      cout << stack[size - 1] << '\n';
    }
  }
};

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  Stack s = Stack();
  string str;
  int num;
  while (tc--) {
    cin >> str;
    if (strcmp(str.c_str(), "push") == 0) {
      cin >> num;
      s.push(num);
    } else if (strcmp(str.c_str(), "top") == 0) {
      s.top();
    } else if (strcmp(str.c_str(), "size") == 0) {
      cout << s.size << '\n';
    } else if (strcmp(str.c_str(), "pop") == 0) {
      s.pop();
    } else if (strcmp(str.c_str(), "empty") == 0) {
      s.empty();
    }
  }
  return 0;
}