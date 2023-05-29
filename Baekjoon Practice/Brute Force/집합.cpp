#include <iostream>

using namespace std;

class Set_operation {
public:
  int bitmask;

public:
  Set_operation() { bitmask = 0; }

public:
  void add(int x) { bitmask |= (1 << x); }
  void remove(int x) { bitmask &= ~(1 << x); }
  bool check(int x) {
    if (bitmask & (1 << x)) {
      return true;
    } else {
      return false;
    }
  }
  void toggle(int x) { bitmask ^= (1 << x); }
  void all() {
    // {1,...,20} 2^21-1하면 0도 포함되므로 -2를 했다!
    // 나중에 보고 헷갈리지 말기
    bitmask = (1 << 21) - 2;
  }
  void empty() { bitmask = 0; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Set_operation s = Set_operation();
  int m;
  cin >> m;
  while (m--) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      int x;
      cin >> x;
      s.add(x);
    } else if (cmd == "remove") {
      int x;
      cin >> x;
      s.remove(x);
    } else if (cmd == "check") {
      int x;
      cin >> x;
      cout << s.check(x) << '\n';
    } else if (cmd == "toggle") {
      int x;
      cin >> x;
      s.toggle(x);
    } else if (cmd == "all") {
      s.all();
    } else if (cmd == "empty") {
      s.empty();
    } else {
      cout << "not valid command\n";
    }
  }
  return 0;
}